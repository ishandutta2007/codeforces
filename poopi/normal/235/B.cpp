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
#define Pss pair<string, string>
#define PLL pair<int64, int64>
#define Inf 1000000
#define Mod 1000000007LL

int n;
double p[100010];
double len, res;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p[i];
        res += p[i] * (2 * len + 1);
        len = p[i] * (len + 1);
    }
    cout << setprecision(9) << fixed << showpoint << res << endl;
    return 0;
}