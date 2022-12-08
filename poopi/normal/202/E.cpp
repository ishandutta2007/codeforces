                                    /* in the name of Allah */
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define int64 long long
#define P pair<int, int>

int n;
int64 cnt[100010], dp2[100010];
int64 dpr[100010], dpl[100010];
priority_queue <int64> q;

int main(){
    cin >> n;
    for(int i = 0; i < n - 1; i++)
        scanf("%d", &cnt[i]);
    dpl[0] = 0;
    for(int i = 1; i < n; i++)
        dpl[i] = (cnt[i - 1] == 1 ? 0 : dpl[i - 1] + cnt[i - 1] - cnt[i - 1] % 2);
    dpr[n - 1] = dp2[n - 1] = 0;
    int64 mx = dpl[n - 1];
    q.push(0);
    for(int i = n - 2; i >= 0; i--){
        dpr[i] = (cnt[i] == 1 ? 0 : dpr[i + 1] + cnt[i] - cnt[i] % 2);
        dp2[i] = dp2[i + 1] + cnt[i] + cnt[i] % 2;
        q.push(dpr[i] + (n - 1 - i) - dp2[i]);
        int64 tmp = q.top() + dp2[i] - (n - 1 - i);
        mx = max(mx, tmp + dpl[i]);
    }
    cout << mx << endl;
    return 0;
}