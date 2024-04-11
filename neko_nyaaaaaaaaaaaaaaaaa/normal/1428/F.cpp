#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 500005;

int get_full(int a, int b) {
	int ans = 0;
	for (int i = 1; i <= a; i++) {
		ans += i*b;
	}
	for (int i = 1; i <= b; i++) {
		ans += i*a;
	}
	return ans;
}

int n, ans;
string s;

vector<int> val(MAXN);
vector<int> pref(MAXN);

void solve(int l, int r) {
	//cout << "Calling " << l << ' ' << r << endl;
	if (l+1 == r) {
		if (s[l] == '1') ans++;
		//cout << "Returning " << l << ' ' << ans << endl;
		return;
	}
	int mid = (l + r)/2;

	solve(l, mid);
	solve(mid, r);

	for (int i = l; i < r; i++) {
		val[i] = pref[i] = 0;
	}

	int cur = 0, cur_mx = 0;
	for (int i = mid-1; i >= l; i--) {
		if (s[i] == '1') cur++;
		else cur = 0;
		val[i] = cur;

		cur_mx = max(cur_mx, cur);
		pref[i] = cur_mx;
	}

	cur = 0, cur_mx = 0;
	for (int i = mid; i < r; i++) {
		if (s[i] == '1') cur++;
		else cur = 0;
		val[i] = cur;

		cur_mx = max(cur_mx, cur);
		pref[i] = cur_mx;
	}

	int petrl = mid-1, petrr = mid;
	while (petrl >= l) {
		if (s[petrl] == '0') break;
		petrl--;
	}
	petrl++;
	while (petrr < r) {
		if (s[petrr] == '0') break;
		petrr++;
	} 
	petrr--;

	int lenl = mid - petrl;
	int lenr = petrr - mid + 1;

	ans += get_full(lenl, lenr);

/*
	cout << "Solving " << l << ' ' << r << endl;
	for (int i = l; i < r; i++) cout << s[i];
		cout << endl;
	cout << "Telling" << endl;
	for (int i = l; i < r; i++) cout << val[i] << ' ';
		cout << endl;
	for (int i = l; i < r; i++) cout << pref[i] << ' ';
		cout << endl;
	cout << petrl << ' ' << petrr << ' ' << lenl << ' ' << lenr << endl;
*/
	// one part full, one part not
	// one end left part first
	int curlen = lenr;
	int sumr = 0;
	for (int i = petrr + 1; i < r; i++) {
		sumr += pref[i];
	}

	int petr = petrr + 1;
	int cnt = 0;

	for (int i = 1; i <= lenl; i++) {
		curlen++;

		while (petr < r && pref[petr] < curlen) {
			sumr -= pref[petr]; cnt++; petr++;
		}

		ans += curlen*cnt + sumr;
	}
	//cout << "OK " << ans << endl;

	// one end right part
	curlen = lenl;
	int suml = 0;
	for (int i = petrl - 1; i >= l; i--) {
		suml += pref[i];
	}

	petr = petrl - 1;
	cnt = 0;

	for (int i = 1; i <= lenr; i++) {
		curlen++;

		while (petr >= l && pref[petr] < curlen) {
			suml -= pref[petr]; cnt++; petr--;
		}

		ans += curlen*cnt + suml;
	}
	//cout << "OK " << ans << endl;

	// both ends not in range
	vector<int> v1, v2;
	for (int i = l; i < petrl; i++) {
		v1.push_back(max(lenl + lenr, pref[i]));
	}
	for (int i = petrr+1; i < r; i++) {
		v2.push_back(max(lenl + lenr, pref[i]));
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	int s1 = v1.size(), s2 = v2.size();

	petr = 0;

	for (int i: v1) {
		while (petr < s2 && v2[petr] < i) petr++;
		ans += i*petr;
	}

	petr = 0;
	for (int i: v2) {
		while (petr < s1 && v1[petr] <= i) petr++;
		ans += i*petr;
	}

/*
	cout << "Vectors" << endl;
	for (int i: v1) cout << i << ' ';
		cout << endl;
	for (int i: v2) cout << i << ' ';
		cout << endl;
	cout << "OK " << ans << endl;
*/
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> s;
	//cout << "Starting string: " << s << endl;
	solve(0, n);
	//cout << "Ending string: " << s << endl;

	cout << ans << '\n';	

	return 0;
}