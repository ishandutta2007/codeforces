/*
*********                                                               ********
*********                                                               *********
**                                                                      **     **                                     **    **
**                                                                      **     **                                           **
*******   *****      **    *****   **     **   *****      **            *********  **    **     **  ******  **    **  **  ******
*******  **   **  * ****  **   **  **     **  **   **  * ****           ********   **    **  * **** *       **    **  **  ******
**       **   **  ***     *******   **   **   *******  ***              **         **    **  ***    ***     **    **  **    **
**       **   **  **      **        **   **   **       **               **         **    **  **        ***  **    **  **    **
**       **   **  **      **   **    ** **    **    *  **               **         **    **  **          *  **    **  **    ** **
**        *****   **       *****      ***      *****   **    *********  **          ******   **     ******   ******   **    ****

**        **  **        **  ******        *******
 **      **    **      **   ********     *********
  **    **      **    **    **     **    **
   **  **        **  **     **      **   **
    ****          ****      **      **   ********
     **            **       **      **    ********
     **            **       **      **          **
     **            **       **     **           **
     **            **       ********     *********
     **            **       ******        ******
*/
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 7;
int n, m, ans[N][3], b[N], tot, stk[N], sttot;
struct node { int a, id;  } f[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> f[i].a, f[i].id = i; 
	L(i, 1, n) cin >> b[i];
	sort(b + 1, b + n + 1);
	sort(f + 1, f + n + 1, [&](node aa, node bb) { return aa.a < bb.a; });
	L(i, 1, n) if(f[i].a > b[i]) {
		while(sttot) {
			if(b[i] < b[stk[sttot]]) swap(b[i], b[stk[sttot]]);
			int det = min(f[i].a - b[i], b[stk[sttot]] - f[stk[sttot]].a);
			++tot, ans[tot][0] = stk[sttot], ans[tot][1] = i, ans[tot][2] = det;
			f[stk[sttot]].a += det, f[i].a -= det;
			if(f[stk[sttot]].a == b[stk[sttot]]) --sttot;
			if(f[i].a == b[i]) break;
		}
		if(f[i].a != b[i]) return cout << "NO\n", 0;
	}
	else if(b[i] > f[i].a) stk[++sttot] = i;
	if(sttot) return cout << "NO\n", 0;
	cout << "YES" << endl;
	cout << tot << endl;
	L(i, 1, tot) cout << f[ans[i][0]].id << " " << f[ans[i][1]].id << " " << ans[i][2] << endl;
	return 0;
}