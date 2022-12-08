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

int n, m, sq;
int64 arr[200010];
int64 sum[1000];
int64 mn[1000];

int64 Min(int str, int end){
    int ids = str / sq;
    int ide = end / sq;
    int64 res = arr[str] + sum[ids];
    while(str <= end && str < (ids + 1) * sq)
        res = min(res, arr[str++] + sum[ids]);
    for(int i = ids + 1; i < ide; i++, str += sq)
        res = min(res, sum[i] + mn[i]);
    for(int i = str; i <= end; i++)
        res = min(res, arr[i] + sum[ide]);
    return res;
}

void Add(int str, int end, int val){
    int ids = str / sq;
    int ide = end / sq;
    while(str <= end && str < (ids + 1) * sq)
        arr[str++] += val;
    for(int i = ids + 1; i < ide; i++, str += sq)
        sum[i] += val;
    for(int i = str; i <= end; i++)
        arr[i] += val;

    mn[ids] = arr[ids * sq];
    for(int i = ids * sq; i < (ids + 1) * sq && i < n; i++)
        mn[ids] = min(mn[ids], arr[i]);
    mn[ide] = arr[ide * sq];
    for(int i = ide * sq; i < (ide + 1) * sq && i < n; i++)
        mn[ide] = min(mn[ide], arr[i]);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sq = sqrt((double)n) + 1;
    for(int i = 0; i * sq < n; i++){
        mn[i] = arr[i * sq];
        for(int j = 1; j < sq; j++)
            mn[i] = min(mn[i], arr[i * sq + j]);
    }
    cin >> m;
    string str;
    getline(cin, str);
    for(int i = 0; i < m; i++){
        getline(cin, str);
        istringstream sin(str);
        int arr[5], cnt = 0;
        while(sin >> arr[cnt])
            cnt++;
        if(cnt == 2){
            if(arr[0] > arr[1]){
                int64 t1 = Min(arr[0], n - 1);
                int64 t2 = Min(0, arr[1]);
                cout << min(t1, t2) << endl;
            }
            else cout << Min(arr[0], arr[1]) << endl;
        }
        else{
            if(arr[0] > arr[1]){
                Add(arr[0], n - 1, arr[2]);
                Add(0, arr[1], arr[2]);
            }
            else Add(arr[0], arr[1], arr[2]);
        }
    }
    return 0;
}