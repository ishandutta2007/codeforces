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

#define Mod 1000000007LL

int64 arr[10000010];

int main(){
    int n;
    cin >> n;
    arr[1] = 0;
    arr[2] = 3;
    for(int i = 3; i <= n; i++)
        arr[i] = (2 * arr[i - 1] + 3 * arr[i - 2]) % Mod;
    cout << arr[n] << endl;
    return 0;
}