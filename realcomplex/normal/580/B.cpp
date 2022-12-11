#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define INF 1e10

void open(){
    freopen("in.txt","r",stdin);
    //freopen("output.txt","w",stdout);
}

main(){
    //open();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    ll cost;
    cin >> n >> cost;
    pair<int,int>V[n+1];
    for(int j = 1;j<=n;j++){
        cin >> V[j].fi >> V[j].se;
    }
    V[0].fi = 0;V[0].se = 0;
    sort(V,V+(n+1));
    ll ans = 0;
    int p = 0;
    ll tek = 0;
    for(int j = 1;j<=n;j++){
        tek+=V[j].se;
        while(V[j].fi-V[p].fi>=cost){
            tek -= V[p].se;
            p++;
        }
        ans = max(ans,tek);
    }
    cout << ans;
    return 0;
}