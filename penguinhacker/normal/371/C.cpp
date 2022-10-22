#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
const int MOD=1e9+7;

string s;
ll cntB=0, cntS=0, cntC=0, numB, numS, numC, pB, pS, pC, money;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s >> numB >> numS >> numC >> pB >> pS >> pC >> money;
	for (char c:s) {
		if (c=='S')
			cntS++;
		else if (c=='B')
			cntB++;
		else
			cntC++;
	}
	ll lb=0;
	ll rb=1e12+1000;
	while (lb<rb) {
		ll mid=(lb+rb+1)/2;
		ll needB=max(0ll, mid*cntB-numB);
		ll needS=max(0ll, mid*cntS-numS);
		ll needC=max(0ll, mid*cntC-numC);
		if (needB*pB+needS*pS+needC*pC<=money)
			lb=mid;
		else
			rb=mid-1;
	}
	cout << rb;
	return 0;
}