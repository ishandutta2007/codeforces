#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int >
#define sz(a) ((int) a.size())
using namespace std;
const int N = 307;
int n, arr[N], atot, l[N], a[N], cl[N], cr[N];
int dp[N][N][N], sv[N][N], vl[N];
/* dp_{i,l,r} :  l;  r */
void cmax (int &x, int y) { if(x < y) x = y; }
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> a[i] >> l[i], cl[i] = a[i] - l[i], cr[i] = a[i] + l[i], arr[++atot] = a[i], arr[++atot] = cl[i], arr[++atot] = cr[i];
	sort(arr + 1, arr + atot + 1), atot = unique(arr + 1, arr + atot + 1) - arr - 1;
	L(i, 1, n) 
		a[i] = lower_bound(arr + 1, arr + atot + 1, a[i]) - arr, cl[i] = lower_bound(arr + 1, arr + atot + 1, cl[i]) - arr, 
		cr[i] = lower_bound(arr + 1, arr + atot + 1, cr[i]) - arr, vl[a[i]] = i;
	memset (dp, -0x3f, sizeof(dp)); 
	dp[1][0][1] = 0;
	arr[0] = -111;
//	L(i, 1, atot) cout << arr[i] << " ";
//	cout << "\n";
	L(i, 1, atot) {
		if(vl[i]) {
//			L(l, 0, i - 1) L(r, i, atot) if(dp[i][l][r] >= 0) cout << arr[i] << " " << arr[l] << " " << arr[r] << " : " << dp[i][l][r] << "\n";
//			cout << "qaqaqaqaqaqaqaq\n";
//			cout << arr[i] << "\n";	
			L(l, 0, i - 1) L(r, i, atot) sv[l][r] = dp[i][l][r]; 
			int oL = cl[vl[i]], oR = cr[vl[i]];
//			cout << arr[oL] << " " << arr[oR] << "\n";
			L(l, 0, i - 1) L(r, i, atot) {
				if(oL <= l) cmax(dp[i][0][r], sv[l][r]);
				cmax(dp[i][l][max(r, oR)], sv[l][r]);
			}
		}
//		L(l, 0, i - 1) L(r, i, atot) if(dp[i][l][r] >= 0) cout << arr[i] << " " << arr[l] << " " << arr[r] << " : " << dp[i][l][r] << "\n";
//		cout << "------------------------------\n";
		if(i != atot) {
			int len = arr[i + 1] - arr[i];
			L(l, 0, i - 1) L(r, i, atot) {
				if (r == i && l == 0) cmax(dp[i + 1][i][i + 1], dp[i][l][r] + len), cmax(dp[i + 1][0][i + 1], dp[i][l][r]);
				else if(r == i) cmax(dp[i + 1][l][i + 1], dp[i][l][r] + len);
				else cmax(dp[i + 1][l][r], dp[i][l][r] + len);
			}
		}
	}
	cout << dp[atot][0][atot] << "\n";
	return 0;
}