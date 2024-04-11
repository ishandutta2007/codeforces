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
const int N=3e5+5;

int n,m,T;
int pre[N];

int main() {
	rep(i,1,N) pre[i]=pre[i-1]^i;
	
	scanf("%d",&T);
	while (T--) {
		int a,b;
		scanf("%d%d",&a,&b);
		int x=b^pre[a-1],ans;
		if (!x) ans=a-1;
		else if (x!=a) ans=a;
		else ans=a+1;
		printf("%d\n",ans+1);
	}
	
	return 0;	
}