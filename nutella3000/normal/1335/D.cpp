#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
  
using namespace std;
const int inf = 1e15 + 7;




signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin.tie(0);
    cout.tie(0);
   	ios_base::sync_with_stdio(0);


   	int t;
   	cin >> t;
   	while(t--) {
   		string s[9];	
   		for(int i = 0;i < 9;i++) cin >> s[i];

   		for(int i = 0;i < 9;i++) {
   			for(int j = 0;j < 9;j++) {
   				if (s[i][j] == '1') s[i][j] = '2';
   			}
   		}
   		for(int i = 0;i < 9;i++) {
   			for(char j : s[i]) cout << j;
   			cout << '\n';
   		}
   	}
}