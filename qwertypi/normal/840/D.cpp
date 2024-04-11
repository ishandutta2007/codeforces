#include <bits/stdc++.h>

template<typename T, typename U> T imin(T& a, U b){ if(a > b) a = b; return a; }
template<typename T, typename U> T imax(T& a, U b){ if(a < b) a = b; return a; }
using namespace std;

int a[300013];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); 
const int B = 600;
struct query{
	int l, r, k, id;
	bool operator< (const query& o) const{
		return l / B < o.l / B || l / B == o.l / B && (l / B % 2 ? o.r < r : o.r > r);
	}
};

vector<query> Q;
int ans[300013];

int cnt[300013];

void add(int id){
	cnt[a[id]]++;
}

void del(int id){
	cnt[a[id]]--;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	int n, q;
	cin >> n >> q;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < q; i++){
		int l, r, k;
		cin >> l >> r >> k; 
		l--; r--;
		Q.push_back({l, r, k, i});
	}
	sort(Q.begin(), Q.end());
	int l = 0, r = -1;
	for(auto q : Q){
		while(l > q.l) add(--l);
		while(l < q.l) del(l++);
		while(r < q.r) add(++r);
		while(r > q.r) del(r--);
		int res = (1 << 30);
		for(int d = 0; d < 120; d++){
			int idx = l + rng() % (r - l + 1);
			if(cnt[a[idx]] * q.k > (r - l + 1)){
				imin(res, a[idx]);
			}
		}
		ans[q.id] = (res == (1 << 30) ? -1 : res);
	}
	for(int i = 0; i < q; i++){
		cout << ans[i] << endl; 
	}
}