                            /* in the name of Allah */
#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

int n, m;
int mat[110][110];
int cost[110];

int main(){
    while(cin >> n >> m){
        int a, b;
        for(int i = 0; i < n; i++)
            cin >> cost[i];
        for(int i = 0; i < m; i++){
            cin >> a >> b;
            a--, b--;
            mat[a][b] = mat[b][a] = true;
        }
        int mn = -1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    if(mat[i][j] && mat[j][k] && mat[k][i]){
                        int t = cost[i] + cost[j] + cost[k];
                        if(mn == -1 || mn > t)
                            mn = t;
                    }
                }
            }
        }
        cout << mn << endl;
    }
    return 0;
}