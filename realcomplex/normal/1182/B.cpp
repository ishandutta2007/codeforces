#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
     
using namespace std;
     
typedef long long ll;
typedef pair<int, int> pii;
     
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
     
mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

int main(){
    fastIO;
    int h, w;
    cin >> h >> w;  
    char s[h][w];
    int cnt = 0;
    for(int i = 0 ; i < h ; i ++ ){
        for(int j = 0 ; j < w; j ++ ){
            cin >> s[i][j];
            if(s[i][j] == '*')
                cnt ++ ;
        }
    }
    int res;
    for(int i = 1 ; i + 1< h ; i ++ ){
        for(int j = 1; j + 1 < w; j ++ ){
            if(s[i][j] == '*' && s[i-1][j] == '*' && s[i+1][j] == '*' && s[i][j+1] == '*' && s[i][j-1] == '*'){
                res = 1;
                for(int t = i - 1; t >= 0 ; t -- ){
                    if(s[t][j] == '.')
                        break;
                    res ++ ;
                }
                for(int t = i + 1; t < h; t ++ ){
                    if(s[t][j] == '.')
                        break;
                    res ++ ;
                }
                for(int t = j - 1; t >= 0 ; t -- ){
                    if(s[i][t] == '.')
                        break;
                    res ++ ;
                }
                for(int t = j + 1; t < w; t ++ ){
                    if(s[i][t] == '.')
                        break;
                    res ++ ;
                }
                if(res != cnt){
                    cout << "NO\n";
                    return 0;
                }
                else{
                    cout << "YES\n";
                    return 0;
                }
            }
        }
    }
    cout << "NO\n";
    return 0;
}