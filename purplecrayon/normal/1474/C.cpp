#include "bits/stdc++.h"
using namespace std;

template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

template <typename K>
struct ms : public map<K, int> {
	using map<K, int>::count;
	using map<K, int>::at;
	using map<K, int>::insert;
	using map<K, int>::erase;
	
	int my_size=0;
	size_t size(){
		return my_size;
	}
	void clear() {
		map<K, int>::clear();
		my_size = 0;
	}
	void er(K x){
		if (count(x)) {
			at(x)--;
			if (!at(x)) erase(x);
			my_size--;
		}
	}
	void add(K x){
		if (count(x)) at(x)++;
		else insert(make_pair(x, 1));
		my_size++;
	}
};

void solve(){
    int n; cin >> n; n*=2;
    vector<int> a(n); for (auto& it : a) cin >> it;

    int v=max_element(a.begin(), a.end())-a.begin();
    for (int i = 0; i < n; i++) if (i != v){
        ms<int> s; vector<pair<int, int>> op; op.reserve(2*n);
        for (int j = 0; j < n; j++) if (j != i && j != v) s.add(a[j]);

        op.emplace_back(a[v], a[i]); bool bad=0;

        int sm=a[v];
        for (int rep = 0; rep < (n-2)/2; rep++){
            int c1=s.rbegin()->first, c2=sm-c1;
            s.er(c1); if (!s.count(c2)){ bad=1; break; }
            s.er(c2); assert(c1 >= c2);
            sm=c1; op.emplace_back(c1, c2);
        }
        if (!bad){
            cout << yes;
            cout << a[v]+a[i] << '\n';
            for (auto it : op) cout << it.first << ' ' << it.second << '\n';
            return;
        }
    }
    cout << no;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    cin >> t_c;
    while (t_c--) solve();
}