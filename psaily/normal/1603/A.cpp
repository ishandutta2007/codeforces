#include <bits/stdc++.h>
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
 
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long double db;
// head 
 
const int N=2e5+5;
int n,a[N];	
// int pr,pri[N],mark[N];

// void pre() {
// 	for (int i=2;i<N;i++) {
// 		if (mark[i]) continue;
// 		pri[++pr]=i;
// 		for (int j=i+i;j<N;j+=i) mark[j]=1;	
// 	}
// }

int main() {
	// pre();
	
	int _;
	for (cin>>_;_;_--) {
		scanf("%d",&n);
		rep(i,1,n+1) scanf("%d",&a[i]);
		bool ok=1;
		rep(i,1,n+1) {
			bool flag=0;
			per(j,i+2,2) {
				if (a[i]%j) {
					flag=1;
					break;
				}
			}
			ok&=flag;
			if (!ok) break; 
		}
		puts(ok?"YES":"NO");
	}
	
	return 0;
}