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
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double db;
// head 
 
const int N=2e5+5;
int n,q;
 
 
int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	
	cin>>n>>q;
	set<int> cand;
	rep(i,-1,n+3) cand.insert(i);
	
	map<int,int> mmap;
	
	while (q--) {
		int tt;
		int l,r,x;
		
		cin>>tt;
		if (tt==0) {
			cin>>l>>r>>x;
			if (x==0) {
				auto it=cand.lower_bound(l);
				while (*it<=r) it=cand.erase(it);	
			}else {
				auto it=mmap.lower_bound(l);
				if (it!=mmap.end()&&r>=it->second) continue;
				mmap[l]=r;
				it=mmap.find(l);
				while (it!=mmap.begin()&&prev(it)->second>=r) mmap.erase(prev(it));
			}
		}else {
			int j;
			cin>>j;
			if (!cand.count(j)) puts("NO");
			else {
				int l=*prev(cand.find(j));
				int r=*next(cand.find(j));
				// for (auto tt:mmap) {
				// 	bug(tt.first),debug(tt.second);
				// }
				// bug(l),debug(r);
				auto it=mmap.upper_bound(l);
				// bug(it->first),debug(it->second);
				if (it!=mmap.end()&&it->second<r) puts("YES");
				else puts("N/A");
			}
		}
	}
	
	return 0;	
}