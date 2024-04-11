/*
_NUUUUUUU_
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<iterator>
#include<map>
#include<deque>
using namespace std;

#define int long long
#define pb push_back
#define ld long double
#define mp make_pair

signed main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		string s;
		cin >> s;
		int l = 0, r = a - 1; 
		while (r > l) {
			if (s[l] == '>' || s[r] == '<') {
				break;
			}
			else {
				l++; r--;
			}
		}
		cout << l << endl;
	}
}