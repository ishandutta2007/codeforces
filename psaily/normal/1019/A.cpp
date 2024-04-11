#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
  
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define mp make_pair
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
// head

const int N=3005;

int n,m;
int cnt[N];
ll ans=linf;
struct node {
	int id,val;
}a[N];
bool cmp(node a,node b) {return a.val<b.val;}

int now[N],mark[N];

void solve(int x) {
	rep(i,1,n+1) mark[i]=0;
	rep(i,1,m+1) now[i]=cnt[i];
	ll res=0,num=0;
	rep(i,1,n+1) {
		node e=a[i];
		if (e.id==1) {mark[i]=1,num++; continue;}
		if (now[e.id]>x) now[e.id]--,num++,res+=a[i].val,mark[i]=1;
	}
	rep(i,1,n+1) {
		if (num>x) break;
		if (!mark[i]) mark[i]=1,num++,res+=a[i].val;
	}
	// bug(x),debug(res);
	ans=min(ans,res);
}

int main() {
	scanf("%d%d",&n,&m);
	rep(i,1,n+1) scanf("%d%d",&a[i].id,&a[i].val),cnt[a[i].id]++;
	sort(a+1,a+1+n,cmp);
	rep(i,0,n+1) solve(i);
	printf("%lld\n",ans);
	return 0;
}