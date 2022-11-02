#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
  
using namespace std;
const int inf = 1e9 + 7;
const int max_n = 1e6 + 3;
int mod = 1e9 + 7;

int n;
int p_hash[max_n], s_hash[max_n], p[max_n];
string a;


bool check(int l, int r) {
	int hash1 = p_hash[r];
	if (l != 0) hash1 = (hash1 - p_hash[l - 1] * p[r - l + 1] % mod + mod) % mod;

	int hash2 = s_hash[l];
	if (r + 1 != n) hash2 = (hash2 - s_hash[r + 1] * p[r - l + 1] % mod + mod) % mod;

	return hash1 == hash2;
}


void scan() {

	int temp[]{(int)1e9 + 21, (int)1e9 + 33, (int)1e9 + 33, (int)1e9 + 87, (int)1e9 + 93, (int)1e9 + 97};

	mod = temp[(rand() % 6LL + 6LL) % 6];


	a.clear();
	cin >> a;
	n = a.size();
	//cout << a << " " << n << '\n' << '\n';

	p[1] = 29;
	for(int i = 2;i <= n;i++) p[i] = p[i - 1] * 29 % mod;

	for(int i = 0;i < n;i++) {
		p_hash[i] = a[i];
		if (i != 0) p_hash[i] += p_hash[i - 1] * p[1] % mod;
	}

	for(int i = n - 1;i >= 0;i--) {
		s_hash[i] = a[i];
		if (i != n - 1) s_hash[i] += s_hash[i + 1] * p[1] % mod;
	}
}

void solve() {
	scan();


	int id1 = 0;
	int id2 = n - 1;
	while(id1 < id2 && a[id1] == a[id2]) {
		id1++;
		id2--;
	}

	//cout << id1 << " " << id2 << '\n';

	int max_id1 = id1 - 1;
	int max_id2 = id2 + 1;
	for(int i = id1;i <= id2;i++) {
		if (check(id1, i)) max_id1 = i;
	}
	for(int i = id2;i >= id1;i--) {
		if (check(i, id2)) max_id2 = i;
	}

	id1--;
	id2++;
	if (max_id1 + (n - id2) > id1 + (n - max_id2)) id1 = max_id1;
	else id2 = max_id2;


	for(int i = 0;i <= id1;i++) cout << a[i];
	for(int i = id2;i < n;i++) cout << a[i];
	cout << '\n';
}






signed main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    srand(0);

    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) {
    	solve();
	}
}