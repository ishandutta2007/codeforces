#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));
typedef long long ll;
typedef long double ld;
const int N=200010;
const int TSZ=1e7;
const ll inf=1e18;
int a[N],b[N];
int cnt[N];
int x[N],y[N];
vector<int>group[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>b[i];
    for (int i=0;i<=n+1;i++){
        cnt[i]=0;
        group[i].clear();
    }
    for (int i=1;i<=n;i++) cnt[b[i]]++;
    for (int i=1;i<=n+1;i++) cnt[i]+=cnt[i-1];
    int k=-1;
    for (int i=0;i<=n;i++){
        if (cnt[i]+i==n){
            k=i;
            break;
        }
    }
    for (int i=1;i<=n;i++) group[b[i]].push_back(i);
    int x=0;
    if (group[x].empty()) x=n+1;
    vector<int>p;
    while (p.size()<n){
        vector<int>nw=group[x];
        for (int y:nw){
            if (group[y].empty()) continue;
            x=y;
            break;
        }
        int pos=-1;
        for (int i=0;i<nw.size();i++){
            if (nw[i]==x) pos=i;
        }
        if (pos!=-1) swap(nw.back(),nw[pos]);
        for (int i:nw) p.push_back(i);
    }
    cout<<k<<'\n';
    for (int i:p) cout<<i<<" ";
    cout<<'\n';


}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    while (tt--){
        solve();
    }
    return 0;

}