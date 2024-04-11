//============================================================================
// Name        : problem4.cpp
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

const int MAX = 55;
ll a, b, m,
	seq[MAX];

void solve() {
	if (a == b) {
		cout << "1 " << a << "\n";
		return;
	}

	if (m >= b - a) {
		cout << "2 " << a << " " << b << "\n";
		return;
	}

	int len = -1;
	seq[0] = a;
	for (int i = 1; i < MAX; i++) {
		seq[i] = 1;
		for (int j = 0; j < i; j++)
			seq[i] += seq[j];

		if (seq[i] > b) {
			len = i;
			break;
		}
	}

	if (len == -1 || len > 50) {
		cout << "-1\n";
		return;
	}

	m--;
	for (int i = 1; i < len; i++) {
		ll mul = 1LL << max(0LL, (ll)len - 1 - i - 1), diff = b - seq[len - 1], amt = min(m, diff / mul);

		ll cpow = -1;
		for (int j = i; j < len; j++) {
			seq[j] += amt << max(0LL, cpow);
			cpow++;
		}
	}

 	if (seq[len - 1] != b) {
		cout << "-1\n";
		return;
	}

	cout << len << " ";
	for (int i = 0; i < len; i++)
		cout << seq[i] << " ";
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int q; scan(q);
	while (q--) {
		scan(a, b, m);
		memset(seq, 0, sizeof seq);
		solve();
	}

	return 0;
}