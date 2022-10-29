#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--) 
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define make_unique(x) { sort(all(x)); x.resize(unique(all(x))-x.begin()); }
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
mt19937 mrand(time(0));
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
typedef vector<int> VI;
const int mod=998244353,inf=1<<30;
// head
typedef unsigned long long ull;
const int N=2e5+5;

int n;
char str[N];
struct hsh {
	ull v1,v2;
	hsh(){}
	hsh(ull a,ull b) {v1=a,v2=b;}
	bool operator == (const hsh&_) const {return v1==_.v1&&v2==_.v2;}
	hsh operator + (const hsh&_) const {return hsh(v1+_.v1,v2+_.v2);}
	hsh operator - (const hsh&_) const {return hsh(v1-_.v1,v2-_.v2);}	
	hsh operator * (int t) {return hsh(v1*t,v2*t);}
	hsh operator * (const hsh&_) const {return hsh(v1*_.v1,v2*_.v2);}
}pw[N],sum[N],rsum[N];

hsh P=hsh(17,13);
hsh gethsh(int l,int r) {
	return sum[r]-sum[l-1]*pw[r-l+1];
}
hsh getrhsh(int l,int r) {
	return rsum[l]-rsum[r+1]*pw[r-l+1];
}
void solve() {
	scanf("%d",&n);
	scanf("%s",str+1);
	sum[0]=rsum[n+1]=hsh(0,0);
	rep(i,1,n+1) sum[i]=sum[i-1]*P+hsh(str[i],str[i]);
	per(i,n+1,1) rsum[i]=rsum[i+1]*P+hsh(str[i],str[i]);

	int cnt=0;
	rep(i,1,n+1) {
		// [1,i-1] [i+1,n]
		hsh pr1=gethsh(1,i-1),pr2=gethsh(i+1,n);
		hsh sf1=getrhsh(1,i-1),sf2=getrhsh(i+1,n);
		
		// bug(i);
		// bug(pr1),debug(pr2);
		// bug(sf1),debug(sf2);
		if (pr1*pw[n-i]+pr2==sf1+sf2*pw[i-1]) cnt++;
	}
	printf("%d\n",cnt);
}

int main() {
	pw[0]=hsh(1,1);
	rep(i,1,N) pw[i]=pw[i-1]*P;
	int _;
	for (scanf("%d",&_);_;_--) {
		solve();
	}

	return 0;
}