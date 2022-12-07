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

ii a[N], b[N * 10];
llint ans = 0;
int n;

void MAIN(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d%d", &a[i].first, &a[i].second);

    int cur = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            if(i != j)
                b[++cur] = ii(a[i].first - a[j].first, a[i].second - a[j].second);

    int cnt = 0;
    sort(b + 1, b + cur + 1);

    for(int i = 1; i <= cur; ++i)
        if(b[i] == b[i - 1]) ++cnt;
        else{
            ans += (cnt * (cnt - 1)) / 2;
            cnt = 1;
        }
    ans += (cnt * (cnt - 1)) / 2;
    printf("%lld", ans / 4);
}