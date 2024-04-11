#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define INF 1e12

void open(){
    freopen("in.txt","r",stdin);
    //freopen("output.txt","w",stdout);
}

main(){
    //open();
    //ini();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k,x;
    cin >> n >> k >> x;
    int v[n];
    for(int j = 0;j<n;j++) cin >> v[j];
    sort(v,v+n);
    reverse(v,v+n);
    int ans= k*x;
    for(int j = k;j<n;j++) ans += v[j];
    cout << ans;
    return 0;
}