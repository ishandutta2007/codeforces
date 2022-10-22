#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=105;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

int T,n,a,b,c;
int p[M],l[M];
string s;
//R  0
//P   1
//S  2

int work(char a)
{
	if (a=='R')return 0;
	if (a=='P')return 1;
	if (a=='S')return 2;
}
int print(int k)
{
	if (k==0)cout<<"R";
	if (k==1)cout<<"P";
	if (k==2)cout<<"S";
}

signed main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>a>>b>>c>>s;int ans=0;
		for (int i=0;i<n;i++)
			l[i+1]=work(s[i]),p[i+1]=-1;
		for (int i=1;i<=n;i++)
			if (l[i]==0)
			{
				if (b!=0)b--,ans++,p[i]=1;
			}
			else if (l[i]==1)
			{
				if (c!=0)c--,ans++,p[i]=2;
			}
			else
			{
				if (a!=0)a--,ans++,p[i]=0;
			}
		if (ans<(n+1)/2){puts("NO");continue;}
		puts("YES");
		for (int i=1;i<=n;i++)
			if (p[i]!=-1)
				print(p[i]);
			else
			{
				if (a!=0)print(0),a--;
				else if (b!=0)print(1),b--;
				else if (c!=0)print(2),c--;
			}
		puts("");
	}
	return 0;
}