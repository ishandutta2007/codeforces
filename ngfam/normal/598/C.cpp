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
pair<int, int> a[N];
pair<long double, int> b[N];
int n;

long double cal(ii u){
    return (atan2(u.second, u.first) * (long double)(180.0)) / (long double)(acos(-1));
}

long double mabs(long double k){
    return (k > 0 ? k : -k);
}

void MAIN(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d%d", &a[i].first, &a[i].second);
        b[i] = make_pair(cal(a[i]), i);
        //if(b[i].first == 0)
    }
    long double how = 361.0;
    sort(b + 1, b + n + 1);
    ii ans = ii(0, 0);
    for(int i = 2; i <= n; ++i){

        if(abs(b[i].first - b[i - 1].first) < how){
             how = mabs(b[i].first - b[i - 1].first);
             ans = ii(b[i].second, b[i - 1].second);
        }
    }

    if(how > 360 - b[n].first + b[1].first) ans = ii(b[1].second, b[n].second);
    if(ans.first < ans.second) swap(ans.first, ans.second);
    printf("%d %d", ans.first, ans.second);
}