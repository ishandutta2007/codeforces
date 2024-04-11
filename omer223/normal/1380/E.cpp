#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0) 
#define foru(i, k, n) for (int i = k; i < n; i++) 
#define ford(i, k, n) for (int i = k; i >= n; i--) 
#define pb push_back
#define ff first 
#define ss second 

#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <string> 
#include <list> 
#include <queue> 
#include <set> 

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 2e5 + 5;
int n, m, tot = 0;
set<int>* piles[sz], tmp[sz];
int pos[sz], sc[sz];

void input() {
	cin >> n >> m;
	foru(i, 0, n) {
		cin >> pos[i];
		tmp[--pos[i]].insert(i);
	}
	foru(i, 0, m) {
		piles[i] = new set<int>(tmp[i]);
		piles[i]->insert(n);
	}
	foru(i, 0, m) {
		int prv = -1;
		for (int x : *piles[i]) {
			if (prv != -1) 
				sc[i] += (x - prv != 1);
			prv = x;
		}
		tot += sc[i];
	}
}

void solve() {
	int x, y;
	cin >> x >> y; x--; y--;
	tot -= (sc[x] + sc[y]);
	int to = x;
	if (piles[x]->size() < piles[y]->size())swap(x, y);
	while (!piles[y]->empty()) {
		auto it = piles[y]->begin();
		int num = *it;
		piles[y]->erase(it);
		if (num == n)continue;
		piles[x]->insert(num);
		it = piles[x]->find(num);
		if (num == *piles[x]->begin()) {
			auto itr = it;
			itr++;
			if (*itr - *it != 1)sc[x]++;
		}
		else {
			auto itl = it, itr = it;
			itl--;
			itr++;
			if (*it - *itl == 1 && *itr - *it == 1)sc[x]--;
			else if (*it - *itl != 1 && *itr - *it != 1)sc[x]++;
		}
	}
	sc[to] = sc[x];
	piles[to] = piles[x];
	tot += sc[to];
	cout << tot << '\n';
}

int main() {
	fast;
	input();
	int q = m-1;
	cout << tot << '\n';
	while (q--)
		solve();
	return 0;
}