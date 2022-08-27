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
int r, c;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> r >> c;
	if(r == 1 && c == 1) return cout << 0 << endl, 0;
	if(r == 1) {
		L(i, 1, c) cout << i + 1 << " ";
		cout << endl;
		return 0;
	}
	if(c == 1) {
		L(i, 1, r) cout << i + 1 << endl;
		return 0;
	}
	L(i, 1, r) L(j, 1, c) cout << i * (j + r) << " \n"[j == c];
	return 0;
}