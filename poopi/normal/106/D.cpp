                                        /* in the name of Allah */
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define int64 long long
#define P pair<int, int>

int n, m, cnt;
int dp[4][1010][1010];
char mat[1010][1010];
int d[100010], len[100010];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector <P> v;
bool res[30];


int get(char ch){
    if(ch == 'N')
        return 0;
    if(ch == 'S')
        return 1;
    if(ch == 'W')
        return 2;
    return 3;
}
int main(){
    string s1, s2;
    while(cin >> n >> m){
        memset(res, false, sizeof res);
        v.clear();
        for(int i = 0; i < n; i++)
            scanf("%s", mat[i]);
        cin >> cnt;
        char ch[10];
        for(int i = 0; i < cnt; i++){
            scanf("%s%d", ch, &len[i]);
            d[i] = get(ch[0]);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == '#')
                    for(int k = 0; k < 4; k++)
                        dp[k][i][j] = -1;
                else if(mat[i][j] != '.')
                    v.push_back(P(i, j));
            }
        }
        /*for(int i = 0; i < 1; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < m; k++){
                    cout << dp[i][j][k] << ' ';
                }
                cout << endl;
            }
            cout << endl;
        }*/
        for(int i = 1; i < n; i++)
            for(int j = 0; j < m; j++)
                if(dp[0][i][j] != -1)
                    dp[0][i][j] = dp[0][i - 1][j] + 1;
        for(int i = n - 2; i >= 0; i--)
            for(int j = 0; j < m; j++)
                if(dp[1][i][j] != -1)
                    dp[1][i][j] = dp[1][i + 1][j] + 1;
        for(int i = 0; i < n; i++)
            for(int j = 1; j < m; j++)
                if(dp[2][i][j] != -1)
                    dp[2][i][j] = dp[2][i][j - 1] + 1;
        for(int i = 0; i < n; i++)
            for(int j = m - 2; j >= 0; j--)
                if(dp[3][i][j] != -1)
                    dp[3][i][j] = dp[3][i][j + 1] + 1;
        /*for(int i = 0; i < 4; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < m; k++){
                    cout << dp[i][j][k] << ' ';
                }
                cout << endl;
            }
            cout << endl;
        }*/
        bool nos = true;
        for(int idx = 0; idx < v.size(); idx++){
            bool good = true;
            int x = v[idx].first, y = v[idx].second;
            for(int i = 0; i < cnt; i++){
                if(dp[d[i]][x][y] >= len[i]){
                    x += len[i] * dir[d[i]][0];
                    y += len[i] * dir[d[i]][1];
                }
                else{
                    good = false;
                    break;
                }
            }
            if(good){
                res[mat[v[idx].first][v[idx].second] - 'A'] = true;
                nos = false;
            }
        }
        if(nos)
            cout << "no solution" << endl;
        else{
            for(int i = 0; i < 26; i++)
                if(res[i])
                    cout << (char)('A' + i);
            cout << endl;
        }
    }
    return 0;
}