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

int n, sz = 1;
int64 tot;
int64 val[200010];
int64 add[200010];

int main(){
    cin >> n;
    int64 a, b, c;
    for(int i = 0; i < n; i++){
        cin >> a;
        if(a == 1){
            cin >> b >> c;
            tot += b * c;
            add[b - 1] += c;
        }
        if(a == 2){
            cin >> b;
            add[sz] = 0;
            val[sz++] = b;
            tot += b;
        }
        if(a == 3){
            sz--;
            tot -= val[sz] + add[sz];
            add[sz - 1] += add[sz];
        }
        cout.precision(9);
        cout.setf(ios::fixed | ios::showpoint);
        cout << (double)tot / sz << endl;
    }
    return 0;
}