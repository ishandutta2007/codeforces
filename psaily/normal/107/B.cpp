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

const int N=1005;
int n,m,h,tot;
int a[N];

int main() {
	scanf("%d%d%d",&n,&m,&h);
	rep(i,1,m+1) scanf("%d",&a[i]),tot+=a[i];
	if (tot<n) return puts("-1"),0;
	int res=tot-a[h];
	if (res<n-1) return puts("1.000000"),0;
	long double ans=1.0;
	rep(i,tot-n+1,tot) ans/=i;
	rep(i,res-n+2,res+1) ans*=i;
	printf("%.10Lf\n",1-ans);   
	return 0;	
}