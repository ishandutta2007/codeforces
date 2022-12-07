/* Riven is not just my life :) */

#include <bits/stdc++.h>
#define prob "test"
typedef long long llint;
using namespace std;
void MAIN();
int main(){
    #ifndef ONLINE_JUDGE
        freopen(prob".inp","r",stdin);
      //  freopen(prob".out","w",stdout);
    #endif
    MAIN();
    return 0;
}
const llint N = 1e6 + 1, mod = 1e9 + 7;
typedef pair<int,int> ii;

int n, s, t, k, pos[N], small[N];
ii a[N];

void MAIN(){
    scanf("%d%d%d%d", &n, &k, &s, &t);
    for(int i = 1; i <= n; ++i){
        scanf("%d%d", &a[i].second, &a[i].first);
    }

    for(int i = 1; i <= k; ++i){
        scanf("%d", pos + i);
    }
    pos[++k] = s;

    sort(a + 1, a + n + 1);
    sort(pos + 1, pos + k + 1);

    small[n] = a[n].second;
    for(int i = n - 1; i >= 1; --i){
        small[i] = min(small[i + 1], a[i].second);
    }

    int l = 1, r = n, mid, val, ans = mod;
    while(l <= r){
        mid = (l + r) >> 1;
        val = a[mid].first;
        int ok = 0;
        for(int i = 1; i <= k; ++i){
            int len = pos[i] - pos[i - 1];
            if(val < len){
                ok = mod *  2;
                break;
            }
            ok += len * 2 - min(val - len, len);
        }
        if(ok <= t){
            r = mid - 1;
            ans = min(ans, mid);
        }
        else{
            l = mid + 1;
        }
    }
    if(ans != mod) printf("%d", small[ans]);
    else printf("-1");
}