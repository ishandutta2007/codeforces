#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))
#define uint unsigned int


    
using namespace std;

struct Fenwick {
	vector <int> aib;
	int n;
	
	inline void init(int _n) {
		n = _n;
		aib.resize(n + 1);
	}
	
	inline void update(int pos, int val) {
		for(int i = pos; i <= n; i += lsb(i)) {
			aib[i] += val;
		}
	}
	
	inline int query(int pos) {
		int ans = 0;
		for(int i = pos; i > 0; i -= lsb(i)) {
			ans += aib[i];
		}
		return ans;
	}
};
  
struct Query {
	int k, pos;
	int qpos;
	bool operator <(const Query &other) const {
		return k < other.k;
	}
};
  
int main() {
#ifdef HOME
    ifstream cin("A.in");
    //ofstream cout("A.out");
#endif
	int i, n, m;
    ios::sync_with_stdio(false);
   	cin.tie(0), cout.tie(0);
	
	cin >> n;
	
	vector <int> arr(n + 1);
	vector < pair <int, int> > a(n + 1);
	
	for(i = 1; i <= n; i++) {
		cin >> a[i].first;
		a[i].second = -i;
		
		arr[i] = a[i].first;
	}
	sort(a.begin(), a.end());
	
	cin >> m;
	
	vector <Query> qry(m + 1);
	for(i = 1; i <= m; i++) {
		cin >> qry[i].k >> qry[i].pos;
		qry[i].qpos = i;
	}
	sort(qry.begin(), qry.end());
	
	vector <int> sol(m + 1);
	Fenwick fen; fen.init(n);
	
	//vector <int> pos;
	int qpos = 1;
	
	for(i = n; i >= 1; i--) {
		
		/*if(i == n || a[i].first != a[i + 1].first) {
			for(auto it : pos) {
				fen.update(it, 1);
			}
			pos.clear(), mx = 0;

			int j = i;
			while(j > 0 && a[j].first == a[i].first) {
				pos.push_back(a[j].second);
				j--;
			}
			reverse(pos.begin(), pos.end());
		}
		mx++;*/
		fen.update(-a[i].second, 1);
		
		while(qpos <= m && qry[qpos].k == n - i + 1) {
			int res = 0;
			for(int step = 1 << 17; step; step >>= 1) {
				if(res + step <= n) {
					//int cur = upper_bound(pos.begin(), pos.end(), res + step) - pos.begin() - 1;
					int cnt = fen.query(res + step);
					if(cnt < qry[qpos].pos) {
						res += step;
					}
				}
			}
			//cerr << res << " " << qry[qpos].qpos << "\n";
			sol[qry[qpos].qpos] = arr[res + 1];
			qpos++;
		}
	}
	
	for(i = 1; i <= m; i++) {
		cout << sol[i] << "\n";
	}
	
	return 0;
}