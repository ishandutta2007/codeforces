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
int n, x, y;
string s, by;

string dup(int cnt, char ch) {
	string ret = "";
	while(cnt--)
		ret += ch;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	scan(n, x, y, s);
	by = "1" + dup(y, '0');

	int cnt = 0;
	for (int ctr = 0; ctr <= y; ctr++) {
		cnt += s[n - 1 - ctr] != by[y - ctr];
	}
	for (int ctr = y + 1; ctr < x; ctr++)
		cnt += s[n - 1 - ctr] != '0';
	printf("%d\n", cnt);

	return 0;
}