//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 1e5 + 10, maxl = 20;
int gcd[maxl][maxn], func[maxn];
LL cnt[maxn * 50];
vector<int> all;
vector<pair<int, LL> > vec;
int n;

inline int gcd_(int st, int en){return __gcd(gcd[func[en - st + 1]][st], gcd[func[en - st + 1]][en - (1 << func[en - st + 1]) + 1]);};

int Next(int st, int ptr, int val){
	int lo = ptr, hi = n - 1;
	while(hi - lo > 1){
		int mid = (lo + hi) >> 1;
		if(gcd_(st, mid) == val)
			lo = mid;
		else
			hi = mid;
	}
	return hi;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> gcd[0][i];
	gcd[0][n++] = 1;
	for(int i = 1; i < maxl; i++)
		for(int j = 0; j + (1 << i) <= n; j++)
			gcd[i][j] = __gcd(gcd[i - 1][j], gcd[i - 1][j + (1 << (i - 1))]);
	for(int i = 2; i < maxn; i++)
		func[i] = func[i >> 1] + 1;
	all.PB(1);
	for(int i = 0; i < n - 1; i++){
		int val = gcd[0][i];
		LL ptr = i;
		while(ptr < n - 1 and val != 1){
			int ptr2 = Next(i, ptr, val);
			vec.PB(MP(val, ptr2 - ptr));
			all.PB(val);
			ptr = ptr2;
			val = gcd_(i, ptr);
		}
		if(ptr < n - 1)
			vec.PB(MP(val, n - ptr - 1));
	}
	sort(all(all));
	all.resize(unique(all(all)) - all.begin());
	for(int i = 0; i < sz(vec); i++){
		int id = lower_bound(all(all), vec[i].L) - all.begin();
		cnt[id] += vec[i].R;
	}
	int q;
	cin >> q;
	while(q--){
		int x;
		cin >> x;
		int id = lower_bound(all(all), x) - all.begin();
		if(id == sz(all) or all[id] != x)
			cout << "0\n";
		else
			cout << cnt[id] << '\n';
	}
	return 0;
}