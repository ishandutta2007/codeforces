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

ll n;
int m,pos;
int dig[18],pw[20];
ll dp[(1<<18)+5][101];
bool mark[10];

int main() {
	scanf("%lld%d",&n,&m);
	pw[0]=1;
	rep(i,1,19) pw[i]=pw[i-1]*10%m;
	while (n) dig[pos++]=n%10,n/=10;
	sort(dig,dig+pos);
	rep(i,0,pos) if (dig[i]&&!mark[dig[i]]) mark[dig[i]]=1,dp[1<<i][dig[i]*pw[pos-1]%m]=1;
	// rep(i,0,pos) printf("%d ",dig[i]); puts("");
	rep(s,0,(1<<pos)-1) rep(j,0,m) if (dp[s][j]) {
		int cnt=0;
		rep(k,0,pos) if (s>>k&1) cnt++;
		rep(k,0,10) mark[k]=0;
		// bug(pos),debug(cnt);
		rep(k,0,pos) if (!(s>>k&1)&&!mark[dig[k]]) {
			mark[dig[k]]=1;
			// if ((s|(1<<k))==((1<<pos)-1)&&(j+pw[pos-1-cnt]*dig[k]%m)%m==0) printf("dp[%d][%d]=%lld\n",s,j,dp[s][j]);
			dp[s|(1<<k)][(j+pw[pos-1-cnt]*dig[k]%m)%m]+=dp[s][j];
		}
	}
	printf("%lld\n",dp[(1<<pos)-1][0]);
	return 0;	
}