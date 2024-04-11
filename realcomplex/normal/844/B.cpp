#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 10000000
#define mp make_pair
#define fi first
#define se second

ll kap(ll n,ll m){
    if(m == 0){
        return 1;
    }
    else{
        ll k = kap(n,m/2);
        if(m%2==1){
            return (k*k)*n;
        }
        else{
            return k*k;
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;
    cin >> n >> m;
    int s[n][m];
    ll cnt[2];
    ll total = -(n*m);
    for(int j = 0;j<n;j++){
        cnt[0] = 0;
        cnt[1] = 0;
        for(int i = 0;i<m;i++){
            cin >> s[j][i];
            cnt[s[j][i]]++;
        }
        total += kap(2,cnt[0])-1;
        total += kap(2,cnt[1])-1;
    }
    for(int j = 0;j<m;j++){
        cnt[0] = 0;
        cnt[1] = 0;
        for(int i = 0;i<n;i++){
            cnt[s[i][j]]++;
        }
        total += kap(2,cnt[0])-1;
        total += kap(2,cnt[1])-1;
    }
    cout << total;
    return 0;
}