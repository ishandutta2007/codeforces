//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
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

const int maxn = 100 * 1000 + 85 - 69;
LL Inf;
pll P[maxn];
LL su[maxn];
set<pll> s;
int n;

LD dist2(pll A, pll B){
	LL dx = A.L - B.L,
	   dy = A.R - B.R;
	return dx * dx + dy * dy;
}

LD dist(pll A, pll B){
	return sqrt(dist2(A, B));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	Inf = 1000;
	Inf *= Inf;
	Inf *= Inf * Inf;
	cin >> n;
	for(int i = 0; i < n; i++){
		LL x;
		cin >> x;
		su[i] = (i == 0 ? 0 : su[i - 1]) + x;
		P[i] = {i, su[i]};
	}
	sort(P, P + n);
	LL ans = Inf;
	LD dis = 1e15;
	int ptr = 0;
	for(int i = 0; i < n; i++){
		while(ptr < i and LD(P[ptr].L) <= P[i].L - dis)
			s.erase(MP(P[ptr].R, P[ptr].L)), ptr++;
		auto it = s.lower_bound(MP(P[i].R - dis, -Inf));
		while(it != s.end() and it->L - P[i].R < dis){
			if(dist(MP(it->R, it->L), P[i]) < dis){
				dis = dist(MP(it->R, it->L), P[i]);
				ans = dist2(MP(it->R, it->L), P[i]);
			}
			it++;
		}
		s.insert(MP(P[i].R, P[i].L));
	}
	cout << ans << endl;
	return 0;
}