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
#define P pair<int, int>
#define Mod 1000000007LL

int rem;
int n, q, nex[310];
int64 t, arr[310];
int64 cnt[100010];
bool mark[310];

int dfs(int idx, int64 val){
    int cc = 0;
    if(nex[idx] != -1)
        cc = dfs(nex[idx], val + arr[idx]);
    t -= cc * arr[idx];
    arr[idx] += val;
    return cc + 1;
}

int main(){
    memset(nex, -1, sizeof nex);
    cin >> n >> q >> t;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int a, b;
    for(int i = 0; i < q; i++){
        cin >> a >> b;
        a--, b--;
        mark[b] = true;
        nex[a] = b;
    }
    rem = q;
    for(int i = 0; i < n; i++)
        if(nex[i] != -1 && !mark[i])
            rem -= dfs(i, 0) - 1;
    if(rem > 0 || t < 0){
        cout << 0 << endl;
        return 0;
    }
    cnt[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j + arr[i] <= t; j++){
            cnt[j + arr[i]] += cnt[j];
            if(cnt[j + arr[i]] >= Mod)
                cnt[j + arr[i]] -= Mod;
        }
    }
    cout << cnt[t] << endl;
    return 0;
}