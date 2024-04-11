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

int n, a[N], b[N];

struct rmq{
    int f[N][20], ok, a[N];

    int inf(){
        if(ok) { return mod; }
        return -mod;
    }

    void init(){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= 20; ++j){
                f[i][j] = inf();
            }
        }
    }

    int combine(int u, int v){
        if(ok) { return min(u, v); };
        return max(u, v);
    }

    void build(){
        for(int i = 1; i <= n; ++i){
            f[i][0] = a[i];
        }

        for(int j = 1; j <= 20; ++j){
            for(int i = 1; i <= n; ++i){
                if(i + (1 << (j - 1)) > n) break;
                f[i][j] = combine(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int ask(int l, int r){
        int lgr = log2(r - l + 1);
        return combine(f[l][lgr], f[r - (1 << lgr) + 1][lgr]);
    }
}tmax, tmin;

void MAIN(){
    scanf("%d", &n);
    srand(time(NULL));
    for(int i = 1; i <= n; ++i){
        a[i] = rand() % 10;
        #ifdef ONLINE_JUDGE
            scanf("%d", a + i);
        #endif // ONLINE_JUDGE

        tmax.a[i] = a[i];
    }
    for(int i = 1; i <= n; ++i){
        b[i] = rand() % 10;
        #ifdef ONLINE_JUDGE
            scanf("%d", b + i);
        #endif // ONLINE_JUDGE
        tmin.a[i] = b[i];
    }

    #ifndef ONLINE_JUDGE
        int ans = 0;
        for(int i = 1; i <= n; ++i){
            int mmax = -mod, mmin = mod;
            cerr << i << " : ";
            for(int j = i; j <= n; ++j){
                mmax = max(mmax, a[j]);
                mmin = min(mmin, b[j]);
                if(mmax == mmin) ++ans, cerr << j << " ";
            }
            cerr << endl;
        }
    cerr << "Answer is : " << ans << endl;
    #endif // ONLINE_JUDGE

    tmin.ok = 1;
    tmax.build();
    tmin.build();
    llint result = 0;
    for(int i = 1; i <= n; ++i){
        int lef = i, rig = n, ansl, ansr = i;
        while(lef <= rig){
            int val = (lef + rig) >> 1;
            int qmax = tmax.ask(i, val), qmin = tmin.ask(i, val);
            if(qmax <= qmin){
                lef = val + 1;
                ansr = max(ansr, val);
            }
            else{
                rig = val - 1;
            }
        }
        if(tmin.ask(i, ansr) != tmax.ask(i, ansr)) continue;

        ansl = n; lef = i; rig = n;
        while(lef <= rig){
            int val = (lef + rig) >> 1;
            int qmax = tmax.ask(i, val), qmin = tmin.ask(i, val);
            if(qmax == qmin) ansl = min(ansl, val);
            if(qmax < qmin){
                lef = val + 1;
            }
            else{
                rig = val - 1;
            }
        }
        result += (ansr - ansl + 1);
        #ifndef ONLINE_JUDGE
            cerr << i << " : " << ansr << " " << rig << endl;
        #endif // ONLINE_JUDGE
    }
    printf("%lld\n", result);
}