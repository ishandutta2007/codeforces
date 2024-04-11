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
int n, m;
ll deg[N], V[N];
int a[N], b[N], tota, totb, cnt, p[N][2];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	L(i, 1, m) {
		int u, v, val; cin >> u >> v >> val;
		deg[u] -= val, deg[v] += val;
	}
	L(i, 1, n) if(deg[i] > 0) b[++totb] = i;
	L(i, 1, n) if(deg[i] < 0) a[++tota] = i, deg[i] = -deg[i];
	int pa = 1, pb = 1;
	while(pa <= tota && pb <= totb) {
		ll v = min(deg[a[pa]], deg[b[pb]]);
		deg[a[pa]] -= v, deg[b[pb]] -= v;
		++cnt, p[cnt][0] = a[pa], p[cnt][1] = b[pb], V[cnt] = v;
		if(deg[a[pa]] == 0) pa ++;
		if(deg[b[pb]] == 0) pb ++; 
	}
	cout << cnt << endl;
	L(i, 1, cnt) cout << p[i][0] << " " << p[i][1] << " " << V[i] << endl;
	return 0;
}