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
int n, m, d[N], a[N];
ll ans, sum;
map< pii, int> mp;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> a[i], sum += a[i];
	cin >> m;
	while(m--) {
		int x, y, z;
		cin >> x >> y >> z;
		int dd = mp[mkp(x, y)];
		if(dd) {
			a[dd] ++;
			if(a[dd] > 0) ans --;
		}
		if(z) {
			if(a[z] > 0) ans ++;
			a[z] --; 
		}
		mp[mkp(x, y)] = z;
		cout << sum - ans << endl;
	}
	return 0;
}