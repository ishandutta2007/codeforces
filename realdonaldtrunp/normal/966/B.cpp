#include "bits/stdc++.h"
using namespace std;


#define MAX 300002

int n;
long long int x1;
long long int x2;

vector<pair<long long int,int> > s;


vector<pair<long long int, int> > sel;


bool filp = false;

vector<int> ans1;
vector<int> ans2;

void outt() {
	puts("Yes");
	if (filp)swap(ans1, ans2);
	cout << ans1.size() << " " << ans2.size() << endl;
	for (int i = 0; i < ans1.size(); i++) {
		if (i)printf(" ");
		printf("%d", ans1[i]);
	}
	puts("");
	for (int i = 0; i < ans2.size(); i++) {
		if (i)printf(" ");
		printf("%d", ans2[i]);
	}
	puts("");
	exit(0);
}
int main() {
	cin >> n >> x1 >> x2;
	for (int i = 0; i < n; i++) {
		long long int a;
		scanf("%lld", &a);
		s.push_back(make_pair(a,i+1) );
	}
	int t = 2;
	while (t--) {
		sort(s.begin(), s.end());
		reverse(s.begin(), s.end());
		sel.clear();
		swap(x1, x2);
		filp ^= true;
		for (int i = 0; i < s.size(); i++) {
			long long int cap = i + 1;
			long long int val = s[i].first;
			cap *= val;
			if ((sel.size() == 0 || sel.back().first <= cap) && cap >= x1) {
				sel.push_back(make_pair(cap, i));
			}
			long long int need = (x2 + val - 1LL) / val;
			long long int least_idx = i - need + 1;
			if (least_idx >= 0) {
				if (sel.size() && sel[0].second < least_idx) {
					for (int i2 = 0; i2 <= sel[0].second; i2++) {
						ans1.push_back(s[i2].second);
					}
					for (int i2 = least_idx; i2 <= i; i2++) {
						ans2.push_back(s[i2].second);
					}
					outt();
				}
			}
		}
	}
	puts("No");
	return 0;
}