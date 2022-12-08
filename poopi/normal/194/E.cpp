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
#define PLL pair<int64, int64>

int a, b, c;
int mat[4][4];
int mark[500010][4];

int calc(){
    if(mat[1][2] > a + b || (a + b - mat[1][2]) % 2) return -1;
    if(mat[1][3] > a + c || (a + c - mat[1][3]) % 2) return -1;
    if(mat[2][3] > b + c || (b + c - mat[2][3]) % 2) return -1;
    int t = (a + b - mat[1][2]) / 2;
    for(int i = 0; i < t; i++)
        mark[i][1] = mark[i][2] = 1;
    for(int i = t; i < a; i++)
        mark[i][1] = 1;
    for(int i = a; i < a + b - t; i++)
        mark[i][2] = 1;
    int t1 = (a + c - mat[1][3]) / 2;
    int t2 = (b + c - mat[2][3]) / 2;
    int x = min(t, min(t1, t2));
    if(t1 - x > a - t || t2 - x > b - t)
        return -1;
    int d1 = a - t - (t1 - x);
    int d2 = b - t - (t2 - x);
    int d3 = c - (t1 + t2 - x);
    x -= min(min(x, d3), min(d1, d2));
    for(int i = 0; i < x; i++)
        mark[i][3] = 1;
    for(int i = 0; i < t1 - x; i++)
        mark[t + i][3] = 1;
    for(int i = 0; i < t2 - x; i++)
        mark[a + i][3] = 1;
    int len = a + b - t + c - (t1 + t2 - x);
    for(int i = a + b - t; i < len; i++)
        mark[i][3] = 1;
    return len;
}

int main(){
    cin >> a >> b >> c;
    cin >> mat[1][2] >> mat[1][3] >> mat[2][3];
    int res = calc();
    cout << res << endl;
    if(res != -1){
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < res; j++)
                cout << (char)('a' + mark[j][i]);
            cout << endl;
        }
    }
    return 0;
}