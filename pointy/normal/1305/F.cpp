// Author: Little09
// Problem: CF1305F Kuroni and the Punishment
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1305F
// Memory Limit: 250 MB
// Time Limit: 2500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=1e6+5,MAXN=1e6;
ll a[N];
int v[N],p[N],cnt,n;
#define ull unsigned long long
ull seed='5'+'a'+'b'+'a'+'k'+'i'+'o'+'i';
ll ans;
inline ull random()
{
	seed^=seed<<13;
	seed^=seed>>17;
	seed^=seed<<5;
	return seed;
}
void init() 
{
    v[1]=1;
    for (int i=2;i<=MAXN;++i) 
	{
        if (!v[i]) p[++cnt]=i;
        for (int j=1;j<=cnt&&i*p[j]<=MAXN;++j) 
		{
            v[i*p[j]]=1;
            if (i%p[j]==0) break; 
        }
    }
}
map<ll,bool>used;
void calc(ll x)
{
	if (used[x]) return;
	used[x]=1;
	ll res=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i]<x) res+=x-a[i];
		else res+=min(a[i]%x,x-a[i]%x);
	}
	ans=min(ans,res);
}
void work(ll x)
{
	if (x<=1) return;
	for (int i=1;i<=cnt;i++)
	{
		if (x%p[i]==0)
		{
			calc(p[i]);
			while (x%p[i]==0) x/=p[i];
		}
	}
	if (x!=1) calc(x);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	init();
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	ans=n;
	for (int i=1;i<=50;i++)
	{
		int x=random()%n+1;
		work(a[x]-1),work(a[x]),work(a[x]+1);
	}
	cout << ans;
	return 0;
}