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

const int N=3005;
int n,a[N];

int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",&a[i]);
	int tot=0;
	rep(i,1,n+1) rep(j,i+1,n+1) if (a[j]<a[i]) tot++;
	int cur=0,ans=0;
	per(i,tot+1,1) {
		if (!cur) ans++;
		else ans+=3;
		cur=1-cur;
	}
	printf("%.6lf\n",(db)ans);
	return 0;	
}