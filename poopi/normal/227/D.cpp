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
#define Max 100010

int n, q;
int64 arr[Max];
int64 sum[Max];
int64 res[Max];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    sum[0] = arr[0];
    for(int i = 1; i < n; i++)
        sum[i] = sum[i - 1] + arr[i];   
    memset(res, -1, sizeof res);
    int k;
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> k;
        if(res[k] == -1){
            res[k] = 0;
            for(int64 j = 1, idx = n - 1 - j; idx >= 0; j *= k, idx -= j)
                res[k] += sum[idx];
        }
        cout << res[k] << ' ';
    }
    cout << endl;
    return 0;
}