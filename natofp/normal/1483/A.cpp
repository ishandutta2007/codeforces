#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>

using namespace std;

const int nax = 1e5 + 5;
int n,m;
vector<int> who[nax];
int cnt[nax];

int ans[nax];

void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++) who[i].clear();

    for(int i=1;i<=m;i++){
        int k; cin>>k;
        while(k--){
            int x; cin>>x;
            who[i].pb(x);
        }
    }
    fill(cnt, cnt + n + 1, 0);
    bool ok = true;
    for(int i=1;i<=m;i++){
        if(who[i].size() == 1){
            cnt[who[i][0]]++;
            if(cnt[who[i][0]] > (m + 1) / 2) ok = false;
            ans[i] = who[i][0];
        }
    }

    if(!ok){
        cout<<"NO"<<"\n";
        return;
    }

    int ma = 0;
    for(int i=1;i<=n;i++) ma = max(ma, cnt[i]);

    cout<<"YES"<<"\n";
    for(int i=1;i<=m;i++){
        if(who[i].size() > 1){
            int one = who[i][0];
            int two = who[i][1];

            if(ma == cnt[one]){
                ans[i] = two;
                cnt[two]++;
                ma = max(ma, cnt[two]);
            }
            else{
                ans[i] = one;
                cnt[one]++;
                ma = max(ma, cnt[one]);
            }

        }
    }

    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";


}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}