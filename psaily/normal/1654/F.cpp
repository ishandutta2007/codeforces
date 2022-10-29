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
const int mod=1e9+7,inf=1<<30;
// head 

const int N=19;
void solve() {
	string s;// [0,m)
	int n,m;
	cin>>n>>s;
	m=1<<n;
	
	VI rk(m);
	vector<PII> a(m);
	rep(i,0,m) rk[i]=s[i]-'a';
	for (int len=1;len<m;len*=2) {// [0,len)
		
		for (int i=0;i<m;i+=len*2) {
			for (int j=0;j<len;j++) {
				a[i+j]=mp(rk[i+j],rk[i+j+len]);
				a[i+j+len]=mp(rk[i+j+len],rk[i+j]);
			}
		}
		auto tmp=a;
		sort(all(tmp));
		tmp.resize(unique(all(tmp))-tmp.begin());
		rep(i,0,m) rk[i]=lower_bound(all(tmp),a[i])-tmp.begin();
	}
	int x=min_element(all(rk))-rk.begin();
	rep(i,0,m) {
		printf("%c",s[i^x]);	
	}
	puts("");
}
int main() {
	solve();

	return 0;	
}