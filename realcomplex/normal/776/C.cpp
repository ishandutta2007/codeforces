#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define INF 1000000000

void open(){
    freopen("in.txt","r",stdin);
    //freopen("output.txt","w",stdout);
}

main(){
    //open();
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    ll k;
    cin >> k;
    ll ans = 0;
    ll v;
    ll s = 0;
    map<ll,int>sk;
    sk[0]++;
    ll p;
    for(int j =0 ;j<n;j++){
        cin >> v;
        s += v;
        p = 1;
        do{
            ans += sk[s-p];
            p*=k;
        }while(p<=(1e14) && p != 1);
        sk[s]++;
    }
    cout << ans;
    return 0;
}