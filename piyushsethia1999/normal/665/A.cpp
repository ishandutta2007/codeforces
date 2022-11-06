#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int a; cin >> a;
	int ta; cin >> ta;
	int b; cin >> b;
	int tb; cin >> tb;
	string s; cin >> s;
	int st = (s[0] - '0') * (60 * 10) + (s[1] - '0') * (60) + (s[3] - '0') * (10) + (s[4] - '0');
	int et = st + ta;
	int ss = 5 * 60;
	int ee = 24 * 60;
	int cnt = 0;
	for (int i = ss; i < ee; i += b) {
		int j = i + tb;
		if (st < j && et > i) cnt++;
	} 	
	cout << cnt << "\n";
}