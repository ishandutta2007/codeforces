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

int x, t, a, b, da, db;

int main(){
    cin >> x >> t >> a >> b >> da >> db;
    string res = "NO";
    if(x == 0) res = "YES";
    for(int i = 0; i < t; i++){
        for(int j = 0; j < t; j++){
            int v = a - da * i + b - db * j;
            int v1 = a - da * i;
            int v2 = b - db * j;
            if(v == x || v1 == x || v2 == x) res = "YES";
        }
    }
    cout << res << endl;
    return 0;
}