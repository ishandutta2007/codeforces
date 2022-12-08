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

int main(){
    int a, c;
    cin >> a >> c;
    int p = 1, b = 0;
    while(a || c){
        b += p * ((c % 3 - a % 3 + 3) % 3);
        p *= 3;
        a /= 3;
        c /= 3;
    }
    cout << b << endl;
    return 0;
}