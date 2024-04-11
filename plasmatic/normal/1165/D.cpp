#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// Scan and Debug
void scan(){}
template<typename F, typename... R> void scan(F &f,R&... r){cin>>f;scan(r...);}
int di_; string dnms_, co_ = ",";
void debug_(){cout<<endl;}
template<typename F, typename... R> void debug_(F f, R... r){while(dnms_[di_] != ',')cout<<dnms_[di_++];di_++;cout<<": "<<f<<",";debug_(r...);}
#define debug(...) dnms_=#__VA_ARGS__+co_,di_=0,debug_(__VA_ARGS__)

const int MAX = 301, MV = 1000001;
int n;
ll divs[MAX];
bool is[MV];

void solve() {
	ll num = divs[0] * divs[n - 1];
	int l = 1, r = n - 2;
	bool flag = true;

	while(l <= r) {
		flag &= divs[l] * divs[r] == num;
		l++; r--;
	}

	for (int i = 0; i < n; ++i)
		is[divs[i]] = true;

	for (int i = 0; i < n; ++i) {
		vector<int> facts;
		int sqn = sqrt(divs[i]);
		for (int j = 2; j <= sqn; j++) {
			if (divs[i] % j == 0) {
				facts.push_back(j);
				if (j * j != divs[i])
					facts.push_back(divs[i] / j);
			}
		}

//		printf("f=%d\n", divs[i]);
//		printf("facts: [");
//		for (int i = 0; i < facts.size(); i++)
//			printf("%d, ", facts[i]);
//		printf("]\n");

		for (int f : facts)
			flag &= is[f];
	}

	if (flag)
		cout << num << "\n";
	else
		cout << "-1\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; scan(t);
	while(t--) {
		scan(n);

		for (int i = 0; i < n; i++)
			scan(divs[i]);
		sort(divs, divs + n);

		memset(is, false, sizeof is);
		solve();
	}

	return 0;
}