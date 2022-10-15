//============================================================================
// Name        : problem1.cpp
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

const int MAX = 101, MV = 202;
int n, tot = 0,
	cnts[MV];
char s;
string buf;

inline int sumBelow(int x) { return (x * (x - 1)) >> 1; }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	scan(n);

	for (int i = 0; i < n; ++i) {
		scan(buf);
		cnts[(int)buf[0]]++;
	}

	int A = 'a', Z = 'z';
	for (int i = A; i <= Z; ++i) {
		int fst = cnts[i] >> 1, snd = cnts[i] - fst;
		tot += sumBelow(fst) + sumBelow(snd);
	}

	cout << tot << "\n";

	return 0;
}