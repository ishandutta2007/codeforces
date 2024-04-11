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
    int n,t,c;
    cin >> n >> t >> c;
    int ans = 0;
    int l = -1e9;
    int k;
    for(int j = 1;j<=n;j++){
        cin >> k;
        if(k>t) l = j;
        if(j>=c){
            if(l<=j-c) ans++;
        }
    }
    cout << ans;
    return 0;
}