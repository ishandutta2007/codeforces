#include "bits/stdc++.h"
using namespace std;

#define MAX 200002

int n;
long long int a;
long long int b;
struct st {
	long long int x;
	long long int A;
	long long int B;
};
vector<st> v;
long long int gcd(long long int a, long long int b) {
	if (a > b) {
		swap(a, b);
	}
	while (a) {
		swap(a, b);
		a %= b;
	}
	return b;
}

pair<long long int, long long int> convert(long long int x, long long int y) {
	//y/x
	if (x == 0LL) {
		return make_pair(LLONG_MIN, LLONG_MIN);
	}
	if (y == 0LL) {
		return make_pair(0LL, 1LL);
	}
	long long int f = x*y / abs(x*y);
	x = abs(x);
	y = abs(y);
	long long int g = gcd(x, y);
	x /= g;
	y /= g;
	y *= f;
	return make_pair(y, x);
}

map<pair<long long int, long long int>, vector<int> > mp;

map<pair<long long int, long long int>, long long int> mpp;

vector<int> un;

map<long long int, long long int> m2;
map<pair<long long int, long long int>, long long int> mmm;
int main() {
	cin >> n >> a >> b;
	int moved = 0;
	for (int i = 0; i < n; i++) {
		long long a2, b, c;
		scanf("%lld%lld%lld", &a2, &b, &c);
		v.push_back({ a2,b,c });
		if (b == 0LL&&c == 0LL) {
			un.push_back(i);
			continue;
		}
		m2[a*b - c]++;
		mp[convert(b, c)].push_back(i);
		mmm[make_pair(b, c)]++;
		moved++;
	}
	long long int ans = 0;
	for (auto it : m2) {
		ans += it.second*(it.second - 1LL);
	}
	for (auto itt : mmm) {
		ans -= itt.second*(itt.second - 1LL);
	}
	for (auto &it : mp) {
		//ans += (long long int)(moved - it.second.size())*(long long int)it.second.size();
		if (it.first.first == (long long int)a) {
			if (it.first.second == 1LL) {
				vector<int> &id = it.second;
				for (int el : id) {
					mpp[make_pair(v[el].A, v[el].B)]++;
				}
				ans += 2LL*un.size()*(long long int)(id.size());
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}