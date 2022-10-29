#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
  
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define fi first
#define se second
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
#define inf 0x3f3f3f3f
 
typedef unsigned long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef pair<long long,int> pli;
typedef double db;
// head
 
const int mod=998244353;
const int N=2e5+5;

int T,n;
int pw[10];
int dig[2];

int main() {
	pw[0]=1;
	rep(i,1,10) pw[i]=pw[i-1]*10;
	scanf("%d",&T);
	while (T--) {
		scanf("%d",&n);
		dig[0]=dig[1]=0;
		rep(i,0,10) dig[i%2]+=((n/pw[i])%10)*pw[i/2];
		int a=dig[0],b=dig[1];
		// bug(a),debug(b);
		printf("%lld\n",1ll*(a+1)*(b+1)-2);
	}
	
	return 0;
}