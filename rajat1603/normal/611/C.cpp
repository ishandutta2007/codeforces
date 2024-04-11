#include "bits/stdc++.h"
using namespace std;
const int N = 555;
int n , m;
string str[N];
int q;
int a , b , c , d;
int sum1[N][N];
int sum2[N][N];
int ans;
int get1(int x1 , int y1 , int x2 , int y2){
    if(y1 > y2 || x1 > x2){
        return 0;
    }
    return sum1[x2][y2] - sum1[x1 - 1][y2] - sum1[x2][y1 - 1] + sum1[x1 - 1][y1 - 1];
}
int get2(int x1 , int y1 , int x2 , int y2){
    if(y1 > y2 || x1 > x2){
        return 0;
    }
    return sum2[x2][y2] - sum2[x1 - 1][y2] - sum2[x2][y1 - 1] + sum2[x1 - 1][y1 - 1];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 1 ; i <= n ; ++i){
        cin >> str[i];
        str[i] = '#' + str[i] + '#';
    }
    str[0] = "";
    for(int i = 0 ; i <= m + 1 ; ++i){
        str[0] += '#';
    }
    str[n + 1] = str[0];
    memset(sum1 , 0 , sizeof(sum1));
    memset(sum2 , 0 , sizeof(sum2));
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            sum1[i][j] = sum1[i - 1][j] + sum1[i][j - 1] - sum1[i - 1][j - 1];
            sum2[i][j] = sum2[i - 1][j] + sum2[i][j - 1] - sum2[i - 1][j - 1];
            if(str[i][j] == '.' && str[i][j + 1] == '.'){
                ++sum1[i][j];
            }
            if(str[i][j] == '.' && str[i + 1][j] == '.'){
                ++sum2[i][j];
            }
        }
    }
    //sum1 stores horizontal
    cin >> q;
    while(q--){
        cin >> a >> b >> c >> d;
        ans = 0;
        ans += get1(a , b , c , d - 1);
        ans += get2(a , b , c - 1 , d);
        cout << ans << "\n";
    }
}