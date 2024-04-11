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
int n;
string s, ans = "";

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	scan(n, s);

	int ansPos = 0;
	for (int i = 0; i < n; i++) {
		if (ansPos % 2 == 0 && s[i] == s[i + 1]) {
			ans += s[i]; ansPos++;
			char last = s[i];

			while(i < n && s[i] == last)
				i++;

			if (i < n) {
				ans += s[i];
				ansPos++;
			}
		}
		else {
			ans += s[i];
			ansPos++;
		}
	}

	if (ans.length() % 2)
		ans = ans.substr(0, ans.length() - 1);

	printf("%d\n%s\n", n - ans.length(), ans.c_str());

	return 0;
}