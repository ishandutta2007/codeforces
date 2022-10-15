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

const int MAX = 200001;
int n, __ptr = 0,
	arr[MAX];

inline int top() { return arr[__ptr]; }
inline int pop() { return arr[__ptr++]; }
inline bool empty() { return __ptr >= n; }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	scan(n);

	for (int i = 0; i < n; ++i)
		scan(arr[i]);
	sort(arr, arr + n);

	int best = 0;
	for (int i = 1; ; i++) {
		while(!empty() && top() < i)
			pop();

		if (empty())
			break;
		else
			pop();

		best = max(best, i);
	}
	printf("%d\n", best);

	return 0;
}