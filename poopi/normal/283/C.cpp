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
#define Inf 10000000
#define Mod 1000000007LL

int n, m;
int val[310], nex[310];
int64 tot, cnt[100010];
bool mark[310];

int calc(int idx, int sum){
    int len = 0;
    tot -= sum;
    val[idx] += sum;
    if(nex[idx] != -1)
        len = calc(nex[idx], val[idx]);
    return len + 1;
}

int main(){
    memset(nex, -1, sizeof nex);
    cin >> n >> m >> tot;
    for(int i = 0; i < n; i++)
        cin >> val[i];
    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        nex[a - 1] = b - 1;
        mark[b - 1] = true;
    }
    
    int rem = m;
    for(int i = 0; i < n; i++)
        if(nex[i] != -1 && !mark[i])
            rem -= calc(i, 0) - 1;

    if(rem > 0 || tot < 0){
        cout << 0 << endl;
        return 0;
    }
    cnt[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = val[i]; j <= tot; j++){
            cnt[j] += cnt[j - val[i]];
            if(cnt[j] >= Mod)
                cnt[j] -= Mod;
        }
    }
    cout << cnt[tot] << endl;
    return 0;
}