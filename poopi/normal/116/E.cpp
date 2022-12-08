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
#define Mod 1000003

int n, m;
int mat[1000010];

int row(int r){
    int s = r * m, e = s + m;
    bool eq = false, dif = false;
    for(int i = s, idx = 0; i < e; i++, idx++){
        if(mat[i] == -1)
            continue;
        int a = mat[i] / 2;
        int b = idx & 1;
        if(a == b) eq = true;
        if(a != b) dif = true;
    }
    if(eq && dif)
        return 0;
    if(eq || dif)
        return 1;
    return 2;
}

int col(int c){
    int s = c, e = n * m + c;
    bool eq = false, dif = false;
    for(int i = s, idx = 0; i < e; i += m, idx++){
        if(mat[i] == -1)
            continue;
        int a = min(mat[i], 3 - mat[i]);
        int b = idx & 1;
        if(a == b) eq = true;
        if(a != b) dif = true;
    }
    if(eq && dif)
        return 0;
    if(eq || dif)
        return 1;
    return 2;
}

int main(){
    while(cin >> n >> m){
        char ch;
        for(int i = 0; i < n * m; i++){
            cin >> ch;
            if(ch == '.')
                mat[i] = -1;
            else mat[i] = (int)(ch - '1');
        }
        int res = 1;
        for(int i = 0; i < n; i++){
            res *= row(i);
            if(res >= Mod)
                res -= Mod;
        }
        for(int i = 0; i < m; i++){
            res *= col(i);
            if(res >= Mod)
                res -= Mod;
        }
        cout << res % Mod << endl;
    }
    return 0;
}