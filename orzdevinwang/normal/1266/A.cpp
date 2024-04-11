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
int n;
char s[N];
void Main() {
	cin >> s + 1;
	n = strlen(s + 1);
	int sum = 0, flag = 0, ze = 0;
	L(i, 1, n) sum += s[i] - '0', flag += ((s[i] - '0') % 2 == 0), ze += (s[i] - '0' == 0);
	if(sum % 3 == 0 && flag > 1 && ze) {
		cout << "red\n";
	}
	else cout << "cyan\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T; cin >> T; while(T--) Main();
	return 0;
}