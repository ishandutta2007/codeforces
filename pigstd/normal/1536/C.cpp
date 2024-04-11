#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int T=read();while(T--) 
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

const int inf=1e18;
int n;string s;
map<double,int>t;

double f(int a,int b)
{
	if (b==0)return inf;
	else return a*1.0/b;
}

signed main()
{
	WT
	{
		n=read();cin>>s;t.clear();
		int cnt1=0,cnt2=0;
		for (int i=0;i<n;i++)
		{
			if (s[i]=='D')cnt1++;
			else cnt2++;double x=f(cnt1,cnt2);
			cout<<t[x]+1<<' ';t[x]++;
		}puts("");
	}
	return 0;
}