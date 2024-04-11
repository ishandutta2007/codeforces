#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair

ll ans = 0;
const int MAXN = 3e5+5;
int cost[MAXN];
int dep[MAXN];
priority_queue<pair<int,int>>depr;

int main(){
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        int n,k;
        cin >> n >> k;
        for(int j = 1;j<=n;j++)cin >> cost[j];
        for(int i = 1;i<=k;i++)depr.push(mp(cost[i],i));
        for(int j = k+1;j<=n+k;j++){
                if(j<=n)depr.push(mp(cost[j],j));
                dep[depr.top().se] = j;
                ans += 1LL * (j-depr.top().se) * depr.top().fi;
                depr.pop();
        }
        cout << ans << "\n";
        for(int i = 1;i<=n;i++)cout << dep[i] << " ";
        return 0;
}