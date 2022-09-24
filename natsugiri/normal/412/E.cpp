#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;


LL dp[2][6];

int main() {
    string S;
    cin >> S;
    LL ans = 0;
    
    for (int i=0, t=0; i<(int)S.size(); i++, t=1-t) {
	if (isalpha(S[i])) dp[1-t][0] = 1;
	else dp[1-t][0] = 0;
	
	if (isalnum(S[i]) || S[i] == '_') dp[1-t][1] = dp[t][0] + dp[t][1];
	else dp[1-t][1] = 0;

	if (S[i] == '@') dp[1-t][2] = dp[t][1] + dp[t][0];
	else dp[1-t][2] = 0;

	if (isalnum(S[i])) dp[1-t][3] = dp[t][2] + dp[t][3];
	else dp[1-t][3] = 0;

	if (S[i] == '.') dp[1-t][4] = dp[t][3];
	else dp[1-t][4] = 0;

	if (isalpha(S[i])) dp[1-t][5] = dp[t][4] + dp[t][5];
	else dp[1-t][5] = 0;
	
	ans += dp[1-t][5];
	
	// for (int j=0; j<6; j++) {
	//     cerr << dp[1-t][j] << ' ';
	// }
	// cerr << endl;
    }

    cout << ans << endl;
    return 0;
}