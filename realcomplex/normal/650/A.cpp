#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define mp make_pair

int main(){
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        int n;
        cin >> n;
        map<int,int>xc,yc;
        map<pair<int,int>,int>cnt;
        int x,y;
        ll ans = 0;
        for(int j = 0;j<n;j++){
                cin >> x >> y;
                ans += xc[x]+yc[y];
                ans -= cnt[mp(x,y)];
                xc[x]++;
                yc[y]++;
                cnt[mp(x,y)]++;
        }
        cout << ans;
        return 0;
}