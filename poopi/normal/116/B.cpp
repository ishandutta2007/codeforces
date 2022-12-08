                            /* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <queue>
#include <set>
using namespace std;

#define int64 long long
#define P pair<int, int>
#define Max 1000010

int n, cnt;
int arr[2 * Max];
char mat[110][110];
bool npr[Max];
priority_queue <int> a, b;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    int m, t;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> mat[i][j];
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] != 'W') continue;
            for(int k = 0; k < 4; k++){
                int ni = i + dir[k][0];
                int nj = j + dir[k][1];
                if(ni >= 0 && ni < n && nj >= 0 && nj < m && mat[ni][nj] == 'P'){
                    cnt++;
                    break;
                }
            }
        }
    }
    cout << cnt 
        << endl;    
    return 0;
}