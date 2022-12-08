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

int n;
int a[110][4];

int main(){
    while(cin >> n){
        for(int i = 0; i < n; i++)
            for(int j = 0; j < 4; j++)
                cin >> a[i][j];
        int res = -1;
        for(int i = 0; i < n; i++){
            bool gd = true;
            for(int j = 0; j < n; j++){
                if(a[i][0] < a[j][0] && a[i][1] < a[j][1] && a[i][2] < a[j][2])
                    gd = false;
            }
            if(gd && (res == -1 || a[i][3] < a[res][3]))
                res = i;
        }
        cout << res + 1 << endl;
    }
    return 0;
}