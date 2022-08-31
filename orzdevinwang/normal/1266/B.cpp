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
ll n;
void Main() {
	cin >> n;
	if(n <= 14) return puts("NO"), void();
	int tmp = n % 14;
	if(tmp < 1 || tmp > 6) return puts("NO"), void();
	else return puts("YES"), void();
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T; cin >> T; while(T--) Main();
	return 0;
}