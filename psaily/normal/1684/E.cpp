#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define make_unique(x) {sort(all(x)); x.resize(unique(all(x))-x.begin());} 
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
	 
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef double db;
const int mod=1e9+7,inf=1<<30;
// head 

const int N=2e5+5;
int n,m,a[N];
void solve() {
	scanf("%d%d",&n,&m);
	vector<int> a(n);
	set<int> st;
	map<int,int> cnt,pcnt;
	// [0,n+1]
	
	rep(i,0,n+1) st.insert(i);
	
	rep(i,0,n) {
		scanf("%d",&a[i]);
		cnt[a[i]]++,pcnt[a[i]]++;
		if (st.count(a[i])) st.erase(a[i]);
	}
	sort(all(a));
	
	int ope=m,mx=0;
	per(i,SZ(a),0) {
		if (!ope) break;
		auto it=st.begin();
		if (*it>=a[i]) { puts("0"); return; }
		st.erase(*it);
		pcnt[a[i]]--;
		if (!pcnt[a[i]]) st.insert(a[i]);
		ope--;
	}
	
	// mex=mx
	mx=*st.begin();
	// debug(mx);
	auto b=a;
	priority_queue<int,vector<int>,greater<int> > q;
	
	for (auto it=cnt.begin();it!=cnt.end();it++) {
		if (it->first>=mx) {
			q.push(it->second);
			debug(it->second);
		}
	}
	int ans=0;
	while (!q.empty()) {
		int t=q.top();
		q.pop();
		if (m>=t) {
			m-=t;
		} else {
			ans++;
		}
	}
	
	printf("%d\n",ans);
}
int main() {
	int _;
	for (scanf("%d",&_);_;_--) {
		solve();
	}
	
	return 0;	
}
/*
1
1 7
1 2 4 3 3 3 5

*/