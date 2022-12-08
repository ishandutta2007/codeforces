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

int n, k;

int main(){
    int a, b;
    int64 t = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        t += b - a + 1;
    }
    cout << k - ((t - 1) % k + 1) << endl;
    return 0;
}