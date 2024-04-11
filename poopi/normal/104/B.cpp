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

int main(){
    while(cin >> n){
        int64 res = 0, a;
        for(int i = 0; i < n; i++){
            cin >> a;
            res += (a - 1) * i + a;
        }
        cout << res << endl;
    }
    return 0;
}