#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 1e10
#define mp make_pair
#define fi first
#define se second

int main(){

    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n,k;
    cin >> n >> k;
    ll sk[n+2];
    sk[0] = 0;
    for(ll j = 1;j<=n;j++){
        cin >> sk[j];
    }
    sk[n+1] = INF;
    sort(sk,sk+n+2);
    vector<ll>w;
    for(ll x = 1;x<=n+1;x++){
        for(ll j = sk[x-1]+1;j<sk[x];j++){
            if(k>=j){
                w.push_back(j);
                k-=j;
            }
            else{
                break;
            }
        }
    }
    cout << w.size() << "\n";
    for(ll j = 0;j<w.size();j++){
        cout << w[j] << " ";
    }
    return 0;
}