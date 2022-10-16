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
int a[nax];
int ans[nax];
void solve(){
    int n,m,x; cin >>n>>m>>x;
    for(int i=1;i<=n;i++) cin >> a[i];
    set<pair<int, int > > xd;
    for(int i=1;i<=m;i++){
        xd.insert(mp(0, i));
    }
    for(int i=1;i<=n;i++){
        int cur = a[i];
        auto najm = (*xd.begin());
        xd.erase(xd.find(najm));
        ans[i] = najm.nd;
        najm.st += cur;
        xd.insert(najm);
    }
    cout<<"YES"<<"\n";
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
    cout << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}