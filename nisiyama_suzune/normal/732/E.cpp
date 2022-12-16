#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n, m, p[220000], s[220000];
pair <pair <long long, long long>, long long> com[220000];
long long a[220000], b[220000];
bool used[220000];

int main () {
	ios::sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);
	cin >> n >> m;
	for (long long i = 0; i < n; i++)
		cin >> p[i];
	for (long long i = 0; i < m; i++)
		cin >> s[i];
	for (long long i = 0; i < n; i++) {
		com[i].first.first = p[i];
		com[i].first.second = 0;
		com[i].second = i;
	}
	sort (com, com + n);
	long long c = 0, u = 0;
	for (long long i = 0; i <= 35; i++) {
		for (long long j = 0; j < m; j++) {
			if (used[j]) continue;
			long long l = lower_bound (com, com + n, make_pair (make_pair (s[j], 0LL), -1LL)) - com;
			if (l < n && com[l].first == make_pair (s[j], 0LL)) {
				a[j] = i;
				b[com[l].second] = j + 1;
				com[l].first.second = -1;
				c++;
				u += i;
				used[j] = true;
			}
			s[j] = (s[j] % 2 ? s[j] / 2 + 1 : s[j] / 2);
		}
	}
	cout << c << " " << u << endl; 
	for (long long i = 0; i < m; i++)
		cout << a[i] << " ";
	cout << endl;
	for (long long i = 0; i < n; i++)
		cout << b[i] << " ";
	cout << endl;
	return 0;
}