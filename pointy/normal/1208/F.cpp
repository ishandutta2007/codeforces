// Author: Little09
// Problem: CF1208F Bits And Pieces
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1208F
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=3e6+5,M=21;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define endl "\n"
#define printYes cout << "Yes\n"
#define printYES cout << "YES\n"
#define printNo cout << "No\n"
#define printNO cout << "NO\n"
#define lowbit(x) ((x)&(-(x)))
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
int n;
int a[N],mn[N];
pii mx[N];
inline pii merge(pii x,pii y)
{
	pii res;
	res.fi=max(x.fi,y.fi);
	res.se=max(max(x.se,y.se),x.fi+y.fi-res.fi);
	return res;
}
bool check(int x)
{
	for (int i=x;i;i=(i-1)&x) if (mn[i]<mx[i^x].se) return 1;
	return mn[0]<mx[x].se;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	memset(mn,20,sizeof(mn));
	for (int i=1;i<=n;i++) mn[a[i]]=min(mn[a[i]],i);
	for (int i=1;i<=n;i++) mx[a[i]]=merge(mx[a[i]],mp(i,0));
	for (int i=0;i<M;i++) for (int j=0;j<(1<<M);j++)
	{
		if ((j&(1<<i))==0) mn[j]=min(mn[j],mn[j^(1<<i)]),mx[j]=merge(mx[j],mx[j^(1<<i)]);
	} 
	int ans=0;
	for (int i=M-1;i>=0;i--) if (check(ans|(1<<i)))  ans|=(1<<i);
	cout << ans;
	return 0;
}