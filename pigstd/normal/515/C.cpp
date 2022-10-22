//AFO countdown:???
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

int n,cnt[20];
string s;

void work(int x,int k)
{
	for (int i=2;i<=x;i++)
	{
		int p=i;
		while(p%7==0)p/=7,cnt[7]+=k;
		while(p%5==0)p/=5,cnt[5]+=k;
		while(p%3==0)p/=3,cnt[3]+=k;
		while(p%2==0)p/=2,cnt[2]+=k;
	}
}

signed main()
{
	n=read();cin>>s;
	for (int i=0;i<n;i++)
		work(s[i]-'0',1);
	for (int i=10;i>=2;i--)
		while(cnt[i])cout<<i,work(i,-1);
	return 0;
}