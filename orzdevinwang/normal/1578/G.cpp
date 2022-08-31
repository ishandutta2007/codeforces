#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
using namespace std;

const int N = 3e5 + 7, inf = 1e9 + 3;

int n, k, a[N], b[N]; 

map < int, int > mp;

vector < pair < int, int > > vc[N];

int tag[N]; 
bool check(int x) {
	int ql = 1; 
	ll sum = 0, cnt = 0;
	L(i, 1, n) {
		tag[i] = b[i] - a[i];
		sum += b[i] - a[i];
		for(auto u : vc[i]) {
			if(u.first >= ql) sum -= u.second;
			tag[u.first] -= u.second;
		}
		while(sum >= x) sum -= tag[ql], ++ql;
		cnt += ql - 1;
	}
	return cnt >= k;
}

int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	cin >> n >> k;
	mp[1] = 0, mp[inf] = -1;
	L(i, 1, n) {
		cin >> a[i] >> b[i];
		
		auto L = --mp.upper_bound(a[i]), R = --mp.upper_bound(b[i]);
		if(L -> first != a[i]) mp[a[i]] = L -> second, L = --mp.upper_bound(a[i]);
		if(R -> first != b[i]) mp[b[i]] = R -> second, R = --mp.upper_bound(b[i]);
		
		int w = L -> first, c = L -> second;
		L -> second = i, ++L;
		if(c) vc[i].emplace_back(make_pair(c, L -> first - w));
		
		while (L != R) {
			w = L -> first, c = L -> second, mp.erase(L++);
			if(c) vc[i].emplace_back(make_pair(c, L -> first - w));
		}	
	}
	
	int l = 1, r = inf, kth = 0;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid)) kth = mid, l = mid + 1;
		else r = mid - 1;
	}

	int ql = 1; 
	ll sum = 0, cnt = 0, ns = 0, cur = 0;
	L(i, 1, n) {
		tag[i] = b[i] - a[i], sum += b[i] - a[i];
		for(auto u : vc[i]) {
			if(u.first >= ql) sum -= u.second;
			else cur -= (ll) u.second * u.first;
			tag[u.first] -= u.second;
		}
		while(sum > kth) sum -= tag[ql], cur += (ll) tag[ql] * ql, ++ql;
		cnt += ql - 1;
		ns += (ql - 1) * sum + cur;
	}
	cout << ns + (k - cnt) * kth << '\n';
	return 0;
}