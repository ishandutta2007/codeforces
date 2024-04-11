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
	int a, b, c;
	int m = 0;
	cin >> a >> b >> c;
	for (int i = 1; i <= 7; i++) {
		int a1 = a, b1 = b, c1 = c, cnt1 = 0, cnt2 = 0, cnt3 = 0;
		for (int j = i; j < i + 7; j++) {
			if (j % 7 == 1 || j % 7 == 4 || j % 7 == 0) {
				cnt1++;
			}
			else if (j % 7 == 2 || j % 7 == 6) {
				cnt2++;
			}
			else {
				cnt3++;
			}
		}
		int mx = min(min(c1 / cnt3, b1 / cnt2), a1 / cnt1);
		a1 -= 3 * mx;
		b1 -= 2 * mx;
		c1 -= 2 * mx;
		int cnt = 0;
		for (int j = i; j <= i + 7; j++) {
			if (j % 7 == 1 || j % 7 == 4 || j % 7 == 0) {
				if (a1 != 0) a1--;
				else {
					cnt += j - i; break;
				}
			}
			else if (j % 7 == 2 || j % 7 == 6) {
				if (b1 != 0) b1--;
				else {
					cnt += j - i; break;
				}
			}
			else {
				if (c1 != 0) c1--;
				else {
					cnt += j - i; break;
				}
			}
		}
		m = max(mx * 7 + cnt, m);
	}
	cout << m;
}