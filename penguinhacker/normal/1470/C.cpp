#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int qry(int x) { // 0-indexed
	cout << "? " << x + 1 << endl;
	int res; cin >> res;
	if (res == -1) exit(0);
	return res;
}
int n, k;
int nxt(int i) {return (i + 1) % n;}
int prv(int i) {return (i + n - 1) % n;}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k; qry(0); qry(0);
	vector<int> cand;
	int cur = 2;
	int found = -1;
	for (int i = 0;; i += cur, cur += 2) {
		if (i >= n) {
			i %= n;
			int x = qry(i);
			if (x != k) found = i;
			break;
		}
		int x = qry(i);
		if (x != k) {found = i; break;}
		cand.push_back(i);
	}
	if (found != -1) {
		if (qry(found) < k) {
			found = nxt(found);
			while(qry(found) < k) found = nxt(found);
		}
		else {
			found = prv(found);
			while(qry(found) > k) found = prv(found);
		}
		assert(qry(found) == k);
		cout << "! " << found + 1 << endl;
	}
	else {
		for (int i : cand) {
			if (qry(nxt(i)) > k && qry(i) == k) {
				cout << "! " << i + 1 << endl;
				return 0;
			}
		}
	}
	return 0;
}