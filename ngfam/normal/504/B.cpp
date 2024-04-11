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
const llint N = 2e5 + 1, mod = 1e9 + 7;

int p[N], n, q[N], hold[N];

struct fenwick{
    int bit[N];
    void upd(int i, int val){
        ++i;
        for(; i < N; i += i & -i) bit[i] += val;
    }
    int get(int i){
        ++i;
        int result = 0;
        for(; i > 0; i &= i - 1) result += bit[i];
        return result;
    }
}fwt, fwt2, fwt3, fwt4;

void MAIN(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", p + i);
    }
    for(int i = 1; i <= n; ++i){
        scanf("%d", q + i);
    }

    for(int i = 0; i < n; ++i){
        fwt.upd(i, 1);
    }

    for(int i = n; i >= 1; --i){
        int base = (n - i + 1);

        if(fwt2.get(p[i]) + fwt3.get(q[i]) + hold[i] >= (base))
            hold[i - 1] = 1;
        fwt2.upd(p[i], 1);
        fwt3.upd(q[i], 1);
    }

    memset(fwt2.bit, 0, sizeof fwt2.bit);
    memset(fwt3.bit, 0, sizeof fwt3.bit);

    for(int i = 0; i < n; ++i){
        fwt2.upd(i, 1);
        fwt3.upd(i, 1);
    }

    for(int i = 1; i <= n; ++i){
        int calc = (fwt2.get(p[i] - 1) + fwt3.get(q[i] - 1) + hold[i]) % (n - i + 1);
        ++calc;
        if(i == n) calc = 1;
        //cerr << calc << " " << hold[i] << endl;
        //cerr << calc << endl;
        int l = 0, r = n - 1, ans = n - 1;
        while(l <= r){
            int val = (l + r) >> 1;
            int base = fwt.get(val);
            if(base == calc){
                ans = min(ans, val);
                r = val - 1;
            }
            if(base < calc){
                l = val + 1;
            }
            if(base > calc){
                r = val - 1;
            }
        }
        fwt.upd(ans, -1);
        printf("%d ", ans);
        fwt2.upd(p[i], -1);
        fwt3.upd(q[i], -1);
    }
}