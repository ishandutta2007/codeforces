#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define pii pair<int, int>
#define db double
#define x first
#define y second
#define sz(a) ((int) (a).size())
#define mkp make_pair
#define vi vector<int>
using namespace std;
const int N = 2e5 + 7;
int n, lef[N], rig[N], p[N];
int mx1, mx2, p1, p2, cnt1, cnt2;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> p[i];
	L(i, 2, n) if(p[i - 1] < p[i]) lef[i] = lef[i - 1] + 1;
	R(i, n - 1, 1) if(p[i + 1] < p[i]) rig[i] = rig[i + 1] + 1;
	L(i, 1, n) mx1 = max(mx1, lef[i]), mx2 = max(mx2, rig[i]);
	L(i, 1, n) if(lef[i] == mx1) cnt1 ++;
	L(i, 1, n) if(rig[i] == mx2) cnt2 ++;
//	cout << mx1 << " " << mx2 << " " << cnt1 << " " << cnt2 << "\n";
	L(i, 1, n) if(cnt1 == 1 && cnt2 == 1 && mx1 == mx2 && mx1 % 2 == 0 && lef[i] == mx1 && rig[i] == mx2) 
		return cout << "1\n", 0;
	cout << "0\n"; 
	return 0;
}