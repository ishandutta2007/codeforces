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
typedef pair<llint,llint> ii;

int n, node = 2;
ii a[N];

double sqr(double x){
    return x * x;
}

double dis(ii u){
    return sqr(u.first - a[1].first) + sqr(u.second - a[1].second);
}

llint mabs(llint u){
    return (u > 0 ? u : -u);
}

llint cal(ii u){
    llint x = a[node].first - a[1].first;
    llint y = a[node].second - a[1].second;
    llint xx = u.first - a[1].first;
    llint yy = u.second - a[1].second;
    return mabs(x * yy - xx * y);
}

void MAIN(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%lld%lld", &a[i].first, &a[i].second);

    for(int i = 3; i <= n; ++i)
        if(dis(a[i]) < dis(a[node])) node = i;

    int ans = -1;
    llint how = mod *mod * 4;

    for(int i = 2; i <= n; ++i){
        if(i != node)
             if(cal(a[i]) < how && cal(a[i]) != 0){
                how = cal(a[i]);
                ans = i;
             }
    }


    printf("1 %d %d", node, ans);

}