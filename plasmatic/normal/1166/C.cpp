//============================================================================
// Name        : problem3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

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
int n, rankSz,
	arr[MAX], tree[MAX];
unordered_map<int, int> cnts;
vector<int> ranks_;
ll tot = 0;

int sum(int x) {
	int sum = 0;
	for (; x; x -= x & -x)
		sum += tree[x];
	return sum;
}

void add(int x, int v) {
	for (; x <= rankSz; x += x & -x)
		tree[x] += v;
}

int rankOf(int co) {
	return upper_bound(ranks_.begin(), ranks_.end(), co) - ranks_.begin();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	scan(n);

	for (int i = 0; i < n; ++i) {
		scan(arr[i]); arr[i] = abs(arr[i]);
		ranks_.push_back(arr[i]);
	}
	sort(ranks_.begin(), ranks_.end());
	ranks_.resize(unique(ranks_.begin(), ranks_.end()) - ranks_.begin());
	rankSz = ranks_.size();
	sort(arr, arr + n, greater<int>());

	for (int i = 0; i < n; ++i) {
		tot += sum(rankOf(arr[i] << 1));
		add(rankOf(arr[i]), 1);
	}

	cout << tot << "\n";

	return 0;
}