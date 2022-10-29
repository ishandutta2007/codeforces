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

typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef double db;
const int mod=998244353,inf=1<<30;
// head 
const int N=1e5+5;
int n,d;
bool isprime(int n) {
	for (int i=2;i*i<=n;i++) {
		if (n%i==0) return 0;	
	}
	return 1;
}
VI Factor(int n) {
	VI e;
	for (int i=2;i*i<=n;i++) {
		if (n%i==0) {
			while (n%i==0) n/=i,e.pb(i);
		}
	}
	if (n!=1) e.pb(n);
	return e;
}
void solve() {
	scanf("%d%d",&n,&d);
	int t=0;
	while (n%d==0) n/=d,t++;
	// bug(t),debug(n);
	if (t<=1) puts("NO");
	else if (!isprime(n)) puts("YES");
	else {
		if (t==2) puts("NO");
		else {
			VI e=Factor(d);
			if (SZ(e)==1) puts("NO");
			else {
				if (t>=4) puts("YES");
				else {// t==3
					int f=0;
					for (auto s:e) {
						if ((s*n)%d) {f=1; break;}	
					}
					puts(f?"YES":"NO");
				}
			}
			
		}
	}
}
int main() {
	int _;
	for (scanf("%d",&_);_;_--) {
		solve();	
	}
	
	return 0;	
}