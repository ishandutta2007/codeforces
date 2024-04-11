#include<bits/stdc++.h>
using namespace std;

const int mod=1000000007;
int n,len,tot,x,ql,qr,q[25010],f[61][25010][2][2];
struct node{int ch[10],fail; bool bo;}t[25010];
char s[1010],l[61],r[61];

void add(int &x,int y) {x=(x+y>=mod?x+y-mod:x+y);}

int calc()
{
	memset(f,0,sizeof(f));
	f[0][0][1][0]=1;
	for (int i=0; i<len; i++)
		for (int j=0; j<=tot; j++)
			for (int l=0; l<2; l++)
				for (int m=0; m<2; m++) if (f[i][j][l][m])
					for (int k=0; k<=(l==0?9:r[i]-'0'); k++)
						add(f[i+1][t[j].ch[k]][l&(k==r[i]-'0')][m|t[t[j].ch[k]].bo],f[i][j][l][m]);
	int ans=0;
	for (int i=0; i<=tot; i++) add(ans,f[len][i][0][1]),add(ans,f[len][i][1][1]);
	return ans;
}

int main()
{
	scanf("%s",s),n=strlen(s),tot=0;
	scanf("%s%s",&l,&r),len=strlen(r);
	for (int i=len-1; i>=0; i--)
		if (l[i]!='0')
		{
			l[i]--;
			for (int j=i+1; j<len; j++) l[j]='9';
			break;
		}
	for (int i=0; i+len/2<=n; i++)
	{
		x=0;
		for (int j=i; j<i+len/2; j++)
			if (t[x].ch[s[j]-'0']) x=t[x].ch[s[j]-'0'];
			else t[x].ch[s[j]-'0']=(++tot),x=tot;
		t[x].bo=1;
	}
	q[ql=qr=1]=0;
	while (ql<=qr)
	{
		x=q[ql++];
		if (!x) 
		{
			t[x].fail=0;
			for (int j=0; j<10; j++) 
			{
				t[t[x].ch[j]].fail=0;
				if (t[x].ch[j]) q[++qr]=t[x].ch[j];
			}
		} else
		{
			for (int j=0; j<10; j++)
				if (t[x].ch[j]) t[t[x].ch[j]].fail=t[t[x].fail].ch[j],q[++qr]=t[x].ch[j];
				else t[x].ch[j]=t[t[x].fail].ch[j];
		}
	}
	int ans=calc();
	for (int j=0; j<len; j++) r[j]=l[j];
	printf("%d\n",(ans-calc()+mod)%mod);
	return 0;
}