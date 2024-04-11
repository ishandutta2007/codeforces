#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define INF 1e9

void open(){
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    pair<int,int>k[n];
    for(int j = 0;j<n;j++){
        cin >> k[j].se >> k[j].fi;
    }
    sort(k,k+n);
    int ans = 0;
    int cur = -1;
    for(int i = 0;i<n;i++){
        if(cur < k[i].se){
            ans++;
            cur = k[i].fi;
        }
    }
    cout << ans;
    return 0;
}