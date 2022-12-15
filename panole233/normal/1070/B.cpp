#include<cstdio>
#include<cstring>
#include<cstdlib>

int t1[10000001][2],t2[10000001][2],tot1,tot2,ans,an[200001][40],ann[200001],n,t[40],x,len,tn;
char s[30];
bool bo,Bo;

void dfs(int x,int y)
{
	if (x&&((!t1[x][0]&&!t1[x][1])||(!t2[y][0]&&!t2[y][1]))) {printf("-1\n"); exit(0);}
	if (t1[x][0]&&t2[y][0]) dfs(t1[x][0],t2[y][0]);
	if (t1[x][1]&&t2[y][1]) dfs(t1[x][1],t2[y][1]);
}

void Dfs(int x,int y)
{
	if (t1[x][0])
	{
		if (!t2[y][0]) 
		{
			ann[++ans]=tn+1;
			for (int i=1; i<=tn; i++) an[ans][i]=t[i];
			an[ans][tn+1]=0;
			for (int i=tn+2; i<=32; i++) an[ans][i]=0;
		} else t[++tn]=0,Dfs(t1[x][0],t2[y][0]),tn--;
	}
	if (t1[x][1])
	{
		if (!t2[y][1])
		{
			ann[++ans]=tn+1;
			for (int i=1; i<=tn; i++) an[ans][i]=t[i];
			an[ans][tn+1]=1;
			for (int i=tn+2; i<=32; i++) an[ans][i]=0;
		} else t[++tn]=1,Dfs(t1[x][1],t2[y][1]),tn--;
	}
}

int main()
{
	scanf("%d",&n); tot1=tot2=0; bo=0;
	t1[0][0]=t1[0][1]=t2[0][0]=t2[0][1]=0;
	for (int i=1; i<=n; i++)
	{
		scanf("%s",s); len=strlen(s);
		if (s[0]=='-')
		{
			x=tn=0;
			for (int j=1; j<len&&s[j]!='/'; j++)
				if (s[j]=='.')
				{
					for (int k=8; k; k--)
						t[tn+k]=(x&1),x>>=1;
					tn+=8; x=0;
				} else x=x*10+s[j]-'0';
			for (int k=8; k; k--)
				t[tn+k]=(x&1),x>>=1;
			tn+=8;
			if (s[len-2]=='/') tn=s[len-1]-'0';
			if (s[len-3]=='/') tn=(s[len-1]-'0')+(s[len-2]-'0')*10;
			if (!tn) Bo=1; else
			{
				x=0;
				for (int j=1; j<=tn; j++)
					if (!t1[x][t[j]])
					{
						if (x&&(!t1[x][t[j]^1])&&x!=tot1) break;
						t1[x][t[j]]=(++tot1); x=tot1;
					} else x=t1[x][t[j]];
				t1[x][0]=t1[x][1]=0;
			}
		} else
		{
			bo=1;
			if (Bo) {printf("-1\n"); return 0;}
			x=tn=0;
			for (int j=1; j<len&&s[j]!='/'; j++)
				if (s[j]=='.')
				{
					for (int k=8; k; k--)
						t[tn+k]=(x&1),x>>=1;
					tn+=8; x=0;
				} else x=x*10+s[j]-'0';
			for (int k=8; k; k--)
				t[tn+k]=(x&1),x>>=1;
			tn+=8;
			if (s[len-2]=='/') tn=s[len-1]-'0';
			if (s[len-3]=='/') tn=(s[len-1]-'0')+(s[len-2]-'0')*10;
			if (!tn) {printf("-1\n"); return 0;} else
			{
				x=0;
				for (int j=1; j<=tn; j++)
					if (!t2[x][t[j]])
					{
						if (x&&(!t2[x][t[j]^1])&&x!=tot2) break;
						t2[x][t[j]]=(++tot2); x=tot2;
					} else x=t2[x][t[j]];
				t2[x][0]=t2[x][1]=0;
			}
		}
	}
	if (!bo) {printf("1\n0.0.0.0/0\n"); return 0;}
	dfs(0,0); ans=0; tn=0; Dfs(0,0);
	printf("%d\n",ans);
	for (int i=1; i<=ans; i++)
	{
		x=0;
		for (int j=1; j<=8; j++) x=(x<<1)+an[i][j];
		printf("%d.",x); x=0;
		for (int j=9; j<=16; j++) x=(x<<1)+an[i][j];
		printf("%d.",x); x=0;
		for (int j=17; j<=24; j++) x=(x<<1)+an[i][j];
		printf("%d.",x); x=0;
		for (int j=25; j<=32; j++) x=(x<<1)+an[i][j];
		printf("%d/",x); x=0;
		printf("%d\n",ann[i]);
	}
	return 0;
}