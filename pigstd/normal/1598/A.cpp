#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=1000;
int n,a[M][3],f[M];
string s1,s2;
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void merge(int x,int y){f[find(x)]=find(y);}

signed main()
{
	WT
	{
		n=read();
		cin>>s1>>s2;int f=1;
		for (int i=1;i<=n;i++)
			a[i][1]=s1[i-1]-'0',a[i][2]=s2[i-1]-'0';
		if (a[1][1]||a[n][2]){NO continue;}
		for (int i=2;i<n;i++)
			if (a[i][1]&&a[i][2])f=0;
		if (f)YES
		else NO
	}
	return 0;
}