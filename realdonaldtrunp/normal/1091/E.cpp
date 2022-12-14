#include"bits/stdc++.h"
using namespace std;

int n;
vector<int> v;
long long int r[500002];

void imp() {
	puts("-1");
	exit(0);
}
vector<int> ans;
int main() {
	cin >> n;
	long long int sum2 = 0;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		sum2 += a;
		if (a == 0)continue;
		v.push_back(a);
	}
	n = v.size();
	if (n == 0) {
		puts("0");
		return 0;
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		r[i] = v[i];
		if (i)r[i] += r[i - 1];
	}
	int pos = v.size() - 1;
	long long int sum = 0;
	long long int mini = 0;
	long long int maxi = n;
	for (int i = v.size() - 1; i >= 0; i--) {
		long long int k = i + 1;
		while (pos > i&&v[pos] <= k) {
			sum += v[pos];
			pos--;
		}
		while (pos+1<v.size()&&v[pos+1] > k) {
			sum -= v[pos+1];
			pos++;
		}
		long long int lef = r[i] - k * (k - 1LL);
		long long int right = sum + (pos - i)*(long long int)(k);
		if (lef > right) {
			if (lef - right > k) {
				imp();
			}
			mini = max(mini, lef - right);
		}
		long long int new_lef = lef - k;
		//new_lef<=right-something
		//something<=right-new_lef
		long long int lim = right - new_lef;
		lim += (pos - i);
		lim = min(lim, v.size() - i - 1LL);
		maxi = min(maxi, lim+k);
	}
	for (int i = mini; i <= maxi; i++) {
		if ((sum2 + i) % 2 == 0) {
			ans.push_back(i);
		}
	}
	if (ans.size() == 0) {
		imp();
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		if (i)printf(" ");
		printf("%d", ans[i]);
	}
	cout << endl;
	return 0;
}