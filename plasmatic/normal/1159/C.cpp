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

const int MAX = 100001;
int n, m,
	a[MAX], b[MAX];
ll tot = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	scan(n, m);

	for (int i = 0; i < n; ++i)
		scan(a[i]);
	sort(a, a + n, greater<int>());

	for (int i = 0; i < m; ++i)
		scan(b[i]);
	sort(b, b + m, greater<int>());

	if (a[0] > b[m - 1]) {
		printf("-1\n");
		return 0;
	}

	int fst = a[0], snd = a[1];
	ll bsum = 0;
	for (int i = 0; i < n; ++i)
		bsum += a[i];
	bsum *= m;

	for (int i = 0; i < m - 1; ++i)
		tot += b[i] - fst;
	if (b[m - 1] > fst)
		tot += b[m - 1] - snd;

	cout << tot + bsum << endl;

	return 0;
}