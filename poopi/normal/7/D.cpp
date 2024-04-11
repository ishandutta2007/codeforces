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
#define B 1000000007LL
#define Max 5000010

int n, sum;
char str[Max];
int64 hs[Max], rhs[Max];
int64 p[Max];
int cnt[Max];

int main(){
    gets(str);
    n = strlen(str);
    rhs[n + 1] = 0;
    for(int i = n; i >= 0; i--)
        rhs[i] = rhs[i + 1] * B + str[i - 1];
    hs[1] = str[0];
    sum = cnt[1] = 1;
    p[0] = 1, p[1] = B;
    for(int i = 2; i <= n; i++){
        int sz = i / 2;
        p[i] = p[i - 1] * B;
        hs[i] = hs[i - 1] * B + str[i - 1];
        if(hs[sz] == rhs[i - sz + 1] - rhs[i + 1] * p[sz])
            cnt[i] = cnt[sz] + 1;
        else cnt[i] = 0;
        sum += cnt[i];
    }
    cout << sum << endl;
    return 0;
}