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

int x, y;

int main(){
    cin >> x >> y;
    int t = max(abs(x), abs(y));
    if(x == 0 && y == 0){
        cout << 0 << endl;
        return 0;
    }
    int res = 4 * (t - 1);
    if(x == t && y == -t + 1);
    else if(x == t && y == -t) res += 4;
    else if(x == t) res += 1;
    else if(y == t) res += 2;
    else if(x == -t) res += 3;
    else res += 4;
    cout << res << endl;
    return 0;
}