#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 1e10
#define fi first
#define se second
#define mp make_pair

int main(){

    int n;
    cin >> n;
    if(n == 1){
        cout << 1;
        exit(0);
    }
    ll t = -INF;
    ll x[n],dis[n];
    int ans = 2;
    for(int i = 0;i<n;i++){
        cin >> x[i] >> dis[i];
    }
    t = x[0];
    for(int j = 1;j<n-1;j++){
        if(x[j]-dis[j]>t){
            t = x[j];
            ans++;
        }
        else if(x[j]+dis[j]<x[j+1]){
            t = x[j]+dis[j];
            ans++;
        }
        else{
            t = x[j];
        }
    }
    cout << ans;
    return 0;
}