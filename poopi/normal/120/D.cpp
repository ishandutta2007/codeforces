                                        /* in the name of Allah */
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <list>
#include <map>
#include <set>

using namespace std;

#define uint unsigned int
#define int64 long long
#define P pair<int, int>
#define Pss pair<string, string>
#define PLL pair<int64, int64>
#define Inf 1000000
#define Mod 1000000007LL

int n, m;
int mat[60][60];
int sum[60];
int arr[3];

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> mat[i][j];
    cin >> arr[0] >> arr[1] >> arr[2];
    int cnt = 0;
    for(int i = 0; i < n; i++){
        sum[i] = 0;
        for(int j = 0; j < m; j++)
            sum[i] += mat[i][j];
        if(i > 0)
            sum[i] += sum[i - 1];
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j + 1 < n; j++){
            int ord[3] = {0, 1, 2};
            bool can = false;
            do{
                if(sum[i] == arr[ord[0]] && sum[j] - sum[i] == arr[ord[1]] && sum[n - 1] - sum[j] == arr[ord[2]])
                    can = true;
            }while(next_permutation(ord, ord + 3));
            if(can) cnt++;
        }
    }
    memset(sum, 0, sizeof sum);
    for(int i = 0; i < m; i++){
        sum[i] = 0;
        for(int j = 0; j < n; j++)
            sum[i] += mat[j][i];
        if(i > 0)
            sum[i] += sum[i - 1];
    }
    for(int i = 0; i < m; i++){
        for(int j = i + 1; j + 1 < m; j++){
            int ord[3] = {0, 1, 2};
            bool can = false;
            do{
                if(sum[i] == arr[ord[0]] && sum[j] - sum[i] == arr[ord[1]] && sum[m - 1] - sum[j] == arr[ord[2]])
                    can = true;
            }while(next_permutation(ord, ord + 3));
            if(can) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}