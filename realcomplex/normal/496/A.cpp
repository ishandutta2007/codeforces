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

signed main(){
    //open();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    int sk[n];
    for(int j = 0;j<n;j++){
        cin >> sk[j];
    }
    sort(sk,sk+n);
    int v[n-1];
    int p = 0;
    int ans = INT_MAX;
    int tek;
    for(int j = 1;j<n-1;j++){
        p = 0;
        tek = 0;
        for(int i = 0;i<n;i++){
            if(i==j) continue;
            v[p] = sk[i];
            p++;
        }
        for(int j = 1;j<n-1;j++){
            tek = max(tek,v[j]-v[j-1]);
        }
        ans = min(ans,tek);
    }
    cout << ans;
    return 0;
}