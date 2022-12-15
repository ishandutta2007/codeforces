#include<cstdio>
#include<cstring>

int n,f[1024],q[10001],mi,mii,x,cnt;
char s[1024][101],str[9],ans[256][101],m[101];
bool b[1024],bo;

int calc(int x,int y) {return x*4+y;}

bool small(int x)
{
	if (f[x]<mi) return 1;
	if (f[x]>mi) return 0;
	for (int i=0; i<mi; i++)
	{
		if (s[x][i]<m[i]) return 1;
		if (s[x][i]>m[i]) return 0;
	}
	return 0;
}

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
	{
		scanf("%s",&str); q[i]=0;
		for (int j=0; j<8; j++) q[i]=q[i]*2+str[j]-'0';
	}
	for (int i=0; i<1024; i++) f[i]=1e9;
	f[calc(15,0)]=1; s[calc(15,0)][0]='x';
	f[calc(51,0)]=1; s[calc(51,0)][0]='y';
	f[calc(85,0)]=1; s[calc(85,0)][0]='z';
	memset(b,0,sizeof(b));
	while (1)
	{
		mi=(1e9)-1; mii=-1; 
		for (int i=0; i<1024; i++)
			if ((!b[i])&&small(i)) 
			{
				mi=f[i]; mii=i;
				for (int j=0; j<mi; j++) m[j]=s[i][j];
			}
		if (mii==-1) break;
		if (mii%4==0) 
		{
			m[0]='!';
			for (int i=0; i<mi; i++) m[i+1]=s[mii][i];
			mi++; x=calc((mii/4)^255,1);
			if (!small(x)) 
			{
				f[x]=mi;
				for (int i=0; i<mi; i++) s[x][i]=m[i];
			}
			mi--;
		} else
		{
			m[0]='!'; m[1]='(';
			for (int i=0; i<mi; i++) m[i+2]=s[mii][i];
			mi+=3; m[mi-1]=')';
			x=calc((mii/4)^255,1);
			if (!small(x))
			{
				f[x]=mi;
				for (int i=0; i<mi; i++) s[x][i]=m[i];
			}
			mi-=3;
		}
		for (int i=0; i<1024; i++)
			if (b[i])
			{
				x=calc(((i/4)&(mii/4)),2);
				if ((!b[x])&&(x!=mii))
				{
					cnt=0;
					if (i%4==3) m[0]='(',cnt++;
					for (int j=0; j<f[i]; j++) m[j+cnt]=s[i][j];
					if (i%4==3) m[f[i]+cnt]=')',cnt++;
					m[cnt+f[i]]='&'; cnt++;
					if (mii%4>1) m[cnt+f[i]]='(',cnt++;
					for (int j=0; j<mi; j++) m[j+cnt+f[i]]=s[mii][j];
					if (mii%4>1) m[cnt+f[i]+mi]=')',cnt++;
					mi+=cnt+f[i]; 
					if (!small(x))
					{
						f[x]=mi;
						for (int j=0; j<mi; j++) s[x][j]=m[j];
					}
					mi-=cnt+f[i];
					cnt=0;
					if (mii%4==3) m[0]='(',cnt++;
					for (int j=0; j<mi; j++) m[j+cnt]=s[mii][j];
					if (mii%4==3) m[mi+cnt]=')',cnt++;
					m[cnt+mi]='&'; cnt++;
					if (i%4>1) m[cnt+mi]='(',cnt++;
					for (int j=0; j<f[i]; j++) m[j+cnt+mi]=s[i][j];
					if (i%4>1) m[cnt+f[i]+mi]=')',cnt++;
					mi+=cnt+f[i]; 
					if (!small(x))
					{
						f[x]=mi;
						for (int j=0; j<mi; j++) s[x][j]=m[j];
					}
					mi-=cnt+f[i];
				}
				x=calc(((i/4)|(mii/4)),3);
				if ((!b[x])&&(x!=mii))
				{
					cnt=0;
					for (int j=0; j<f[i]; j++) m[j+cnt]=s[i][j];
					m[cnt+f[i]]='|'; cnt++;
					if (mii%4==3) m[cnt+f[i]]='(',cnt++;
					for (int j=0; j<mi; j++) m[j+cnt+f[i]]=s[mii][j];
					if (mii%4==3) m[cnt+f[i]+mi]=')',cnt++;
					mi+=cnt+f[i]; 
					if (!small(x))
					{
						f[x]=mi;
						for (int j=0; j<mi; j++) s[x][j]=m[j];
					}
					mi-=cnt+f[i];
					cnt=0;
					for (int j=0; j<mi; j++) m[j+cnt]=s[mii][j];
					m[cnt+mi]='|'; cnt++;
					if (i%4==3) m[cnt+mi]='(',cnt++;
					for (int j=0; j<f[i]; j++) m[j+cnt+mi]=s[i][j];
					if (i%4==3) m[cnt+f[i]+mi]=')',cnt++;
					mi+=cnt+f[i]; 
					if (!small(x))
					{
						f[x]=mi;
						for (int j=0; j<mi; j++) s[x][j]=m[j];
					}
					mi-=cnt+f[i];
				}
			}
		b[mii]=1;
	}
	for (int i=0; i<256; i++)
	{
		mi=(1e9)-1; mii=-1;
		for (int j=0; j<4; j++)
			if (small(calc(i,j)))
			{
				mi=f[calc(i,j)];
				for (int k=0; k<mi; k++) m[k]=s[calc(i,j)][k];
			}
		for (int j=0; j<mi; j++) ans[i][j]=m[j];
	}
	for (int i=1; i<=n; i++) puts(ans[q[i]]);
	return 0;
}