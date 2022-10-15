#include <iostream>
#include <vector>

using namespace std;

int n;
string a[3333];
string b[3333];
int s[3333];
int l[3333];
int r[3333];

void fail() {
	cout << "NO\n";
	exit(0);
}

vector<int> create_z(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i=1; i<n; i++) {
        z[i] = max(0,min(z[i-l],r-i));
        while (i+z[i]<n && s[z[i]] == s[i+z[i]]) z[i]++;
        if (i+z[i] > r) {
            l=i; r=i+z[i];
        }
    }
    return z;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	int z = -1;
	for (int i = 1; i <= n; i++) {
		s[i] = a[i].size();
		l[i] = r[i] = -1;
		for (int j = 0; j < s[i]; j++) {
			if (a[i][j] != b[i][j]) {
				if (l[i] == -1) l[i] = j;
				r[i] = j;
			}
		}
		if (l[i] == -1) continue;
		int u = r[i]-l[i]+1;
		if (z == -1) z = u;
		if (z != u) fail();
	}
	while (true) {
		bool ok = true;
		char h = '#';
		for (int i = 1; i <= n; i++) {
			if (l[i] == -1) continue;
			if (l[i] == 0) {ok = false; break;}
			if (h == '#') h = a[i][l[i]-1];
			if (a[i][l[i]-1] != h) {ok = false; break;}
		}
		if (!ok) break;
		for (int i = 1; i <= n; i++) {
			if (l[i] == -1) continue;
			l[i]--;
		}
	}
	while (true) {
		bool ok = true;
		char h = '#';
		for (int i = 1; i <= n; i++) {
			if (l[i] == -1) continue;
			if (r[i] == s[i]-1) {ok = false; break;}
			if (h == '#') h = a[i][r[i]+1];
			if (a[i][r[i]+1] != h) {ok = false; break;}
		}
		if (!ok) break;
		for (int i = 1; i <= n; i++) {
			if (l[i] == -1) continue;
			r[i]++;
		}
	}
	string ua, ub;
	for (int i = 1; i <= n; i++) {
		if (l[i] == -1) continue;
		string fa, fb;
		fa = a[i].substr(l[i],r[i]-l[i]+1);
		fb = b[i].substr(l[i],r[i]-l[i]+1);
		if (ua == "") ua = fa;
		if (ub == "") ub = fb;
		if (ua != fa) fail();
		if (ub != fb) fail();
	}
	string zz = ua;
	zz += "#";
	for (int i = 1; i <= n; i++) {
		if (l[i] == -1) {
			zz += a[i];
		} else {
			zz += a[i].substr(0,r[i]);
		}
		zz += "#";
	}
	auto cz = create_z(zz);
	for (int i = 1; i < cz.size(); i++) {
		if (cz[i] >= ua.size()) fail();
	}
	cout << "YES\n";
	cout << ua << "\n";
	cout << ub << "\n";
}