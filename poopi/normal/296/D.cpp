                                /* in the name of Allah */

#include <algorithm>
#include <iostream>
#include <memory.h>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <list>
#include <map>

using namespace std;

#define int64 long long
#define P pair<int, double>

int n, x[510];
int64 mat[510][510];
int64 sh[510][510];
int64 res[510];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> mat[i][j];
    for(int i = 0; i < n; i++){
        cin >> x[i];
        x[i]--;
    }
    res[n - 1] = 0;
    for(int i = n - 2; i >= 0; i--){
        for(int j = i + 1; j < n; j++){
            sh[x[i]][x[j]] = mat[x[i]][x[j]];
            sh[x[j]][x[i]] = mat[x[j]][x[i]];
            for(int k = i + 1; k < n; k++){
                sh[x[i]][x[j]] = min(sh[x[i]][x[j]], mat[x[i]][x[k]] + sh[x[k]][x[j]]);
                sh[x[j]][x[i]] = min(sh[x[j]][x[i]], sh[x[j]][x[k]] + mat[x[k]][x[i]]);
            }
            res[i] += sh[x[i]][x[j]] + sh[x[j]][x[i]];
        }
        for(int j = i + 1; j < n; j++){
            for(int k = i + 1; k < n; k++){
                sh[x[j]][x[k]] = min(sh[x[j]][x[k]], sh[x[j]][x[i]] + sh[x[i]][x[k]]);
                res[i] += sh[x[j]][x[k]];
            }
        }
    }
    for(int i = 0; i < n; i++)
        cout << res[i] << ' ';
    cout << endl;
    return 0;
}