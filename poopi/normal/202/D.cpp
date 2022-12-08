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

int n, m, x, y;
int mat[1010][1010];
int64 r[1010], c[1010];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &mat[i][j]);
            r[i] += mat[i][j];
            c[j] += mat[i][j];
        }
    }
    x = y = -1;
    int64 mxx = 0, mxy = 0;
    for(int i = 0; i <= n; i++){
        int64 tot = 0;
        for(int j = 0; j < n; j++){
            int64 d = abs(i - j) * 4 + (j < i ? -2 : 2);
            tot += d * d * r[j];
        }
        if(x == -1 || mxx > tot)    {
            mxx = tot;
            x = i;
        }
    }
    for(int i = 0; i <= m; i++){
        int64 tot = 0;
        for(int j = 0; j < m; j++){
            int64 d = abs(i - j) * 4 + (j < i ? -2 : 2);
            tot += d * d * c[j];
        }
        if(y == -1 || mxy > tot)    {
            mxy = tot;
            y = i;
        }
    }
    cout << mxx + mxy << endl;
    cout << x << ' ' << y << endl;
    return 0;
}