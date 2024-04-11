#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
bool adj[6060][6060];
pair<int, int> a[6060];

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> a[i].first >> a[i].second;
        for (int j=0;j<i;j++) if ((((a[i].first - a[j].first)/2)&1) || (((a[i].second - a[j].second)/2)&1)){
            adj[i][j] = adj[j][i] = true;
        }
    }
    ll ans1 = 0, ans2 = 0;
    for (int i=0;i<n;i++){
        int cnt0 = 0, cnt1 = 0;
        for (int j=0;j<n;j++) if (i!=j){
            if (!adj[i][j]) cnt0++;
            else cnt1++;
        }
        ans1 += (ll)cnt0*(cnt0-1)/2;
        ans2 += (ll)cnt0*cnt1;
    }
    ans1 /= 3, ans2 /= 2;
    cout << ans1+ans2;
    return 0;
}