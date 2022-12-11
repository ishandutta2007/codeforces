#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first 
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 2010;
int dp[N][N];
int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        string t;
        cin >> t;
        int n = t.size();
        for(int i = 0 ; i < n; i ++) {
            for(int j = 0 ; j < n; j ++ ){
                dp[i][j] = -1;
            }
        }
        int j;
        int sa, sb;
        for(int sz = 2; sz <= n; sz += 2){
            for(int i = 0 ; i + sz - 1 < n; i ++ ){
                j = i + sz - 1;
                if(sz == 2){
                    if(t[i] == t[i + 1]){
                        dp[i][j] = 1; // draw
                    }
                    else{
                        dp[i][j] = 0; // WIN
                    }
                }
                else{
                    // 
                    sa = 0;
                    // we make a move that makes it (i + 1, j)
                    if(dp[i + 1][j - 1] == 2 || dp[i + 2][j] == 2) sa = 2; // lose 
                    else{
                        if(dp[i + 1][j - 1] == 1){
                            if(t[i] < t[j]) sa = max(sa, 0);
                            else if(t[i] == t[j]) sa = max(sa, 1);
                            else sa = max(sa, 2);
                        }
                        if(dp[i + 2][j] == 1){
                            if(t[i] < t[i + 1]) sa = max(sa, 0);
                            else if(t[i] == t[i + 1]) sa = max(sa, 1);
                            else sa = max(sa, 2);
                        }
                    }
                    // we make a move that makes it (i, j - 1)
                    sb = 0;
                    if(dp[i + 1][j - 1] == 2 || dp[i][j - 2] == 2) sb = 2;
                    else{
                        if(dp[i + 1][j - 1] == 1){
                            if(t[i] > t[j]) sb = max(sb, 0);
                            else if(t[i] == t[j]) sb = max(sb, 1);
                            else sb = max(sb, 2);
                        }
                        if(dp[i][j - 2] == 1){
                            if(t[j] < t[j - 1]) sb = max(sb, 0);
                            else if(t[j] == t[j - 1]) sb = max(sb, 1);
                            else sb = max(sb, 2);
                        }
                    }
                    dp[i][j] = min(sa, sb);
                }
            }
        }
        if(dp[0][n - 1] == 0){
            cout << "Alice\n";
        }
        else if(dp[0][n - 1] == 1){
            cout << "Draw\n";
        }
        else{
            cout << "Bob\n";
        }
    }
    return 0;
}