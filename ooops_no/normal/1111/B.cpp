#include <iostream>
#include<string>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

#define ll long long
#define ld long double


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(20);
	ld n, maxs, k;
	cin >> n >> maxs >> k;
	int now = n - 1;
	int l = 0;
	ld sum = 0;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		sum += a;
		v[i] = a;
	}
	if (sum == v[0] * n ){
        if (n < k){
            cout << v[0] + (ld) (min(k - n + 1, maxs));
            return 0;
        }
	}
	vector<int> used(n);
	sort(v.begin(), v.end());
	int sz = v.size();
	for (int i = 0; i < k; i++) {
		if (sz == 1) {
			if (used[n - 1] != maxs) {
				sum++;
				used[n - 1]++;
			}
			continue;
		}
		if (now >= l) {
			if (((sum + 1) / sz) > (sum - v[l]) / (sz - 1)) {
				used[now]++;
				v[now]++;
				if (now == maxs) {
					now--;
				}
				sum++;
			}
			else {
				sum -= v[l];
				sz--;
				l++;
			}
		}
		else {
			sum -= v[l];
			sz--;
			l++;
		}
	}
	cout << sum / sz;
}