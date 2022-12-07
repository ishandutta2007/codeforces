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

int z[N], d, c, n, l, r, total[N], f[N], g[N], ok[N];
char s[N];

void MAIN(){
    scanf("%s", s + 1);
    n = strlen(s + 1);

    z[1] = n; total[n] = 1;
    for(int i = 2; i <= n; ++i){
        if(r < i){
            l = r = i;
            while(r <= n && s[r] == s[r - l + 1]) ++r;
            z[i] = r - l; --r;
        }
        else{
            int ii = i - l + 1;
            if(z[ii] < r - i + 1) z[i] = z[ii];
            else{
                l = i;
                while(r <= n && s[r] == s[r - l + 1]) ++r;
                z[i] = r - l; --r;
            }
        }
        ++total[z[i]];
    }
    int sl = 0;

    for(int i = n; i >= 1; --i){
        if(z[i] == n - i + 1){
            ok[z[i]] = 1;
            ++sl;
        }
    }

    for(int i = n - 1; i >= 1; --i){
        total[i] += total[i + 1];
    }

    printf("%d\n", sl);
    for(int i = 1; i <= n; ++i){
         if(ok[i]) printf("%d %d\n", i, total[i]);
    }
}