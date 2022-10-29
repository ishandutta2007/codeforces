#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
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
typedef unsigned long long ull;
// head

const int N=2e5+5;
int n,m,d,a[N];
multiset<pii> mst;
int ans[N];

int main() {
	cin>>n>>m>>d;
	rep(i,1,n+1) scanf("%d",&a[i]),mst.insert(mp(a[i],i));
	int res=0;
	rep(i,1,n+1) {
		if (mst.empty()) break;
		res=i;
		multiset<pii>::iterator it=mst.begin(),nxt;
		int las=(*it).fi;
		ans[(*it).se]=i,mst.erase(it);
		while (!mst.empty()) {
			nxt=mst.lower_bound(mp(las+d+1,0));
			if (nxt==mst.end()) break;
			las=(*nxt).fi,ans[(*nxt).se]=i,mst.erase(nxt);
			if (las+d+1>m) break;
		}
	}
	printf("%d\n",res);
	rep(i,1,n+1) printf("%d ",ans[i]); puts("");
	return 0;	
}