//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=2500010;
pair<int,int> a[N];
pair<int,int> used[N*2];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i].first,a[i].second=i;
    sort(a+1,a+n+1);
    vector<int>ind;
    for (int i=2;i<=n;i++){
        if (a[i].first==a[i-1].first) ind.push_back(i);
    }
    if (ind.size()>=2 && ind[0]+1<ind.back()){
        cout<<"YES\n";
        cout<<a[ind[0]-1].second<<" "<<a[ind.back()-1].second<<" "<<a[ind[0]].second<<" "<<a[ind.back()].second<<endl;
        return;
    }
    if (!ind.empty()){
        used[a[ind[0]-1].first+a[ind[0]].first]={ind[0]-1,ind[0]};
    }
    for (int i=1;i<=n;i++){
        if (a[i].first==a[i-1].first) continue;
        for (int j=i+1;j<=n;j++){
            if (a[j].first==a[j-1].first) continue;
            int x=used[a[i].first+a[j].first].first;
            int y=used[a[i].first+a[j].first].second;
            if (x){
                cout<<"YES\n";
                cout<<a[x].second<<" "<<a[y].second<<" "<<a[i].second<<" "<<a[j].second<<endl;
                return;
            }
            used[a[i].first+a[j].first]={i,j};
        }
    }
    cout<<"NO\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
/*
4
1 2 2 2
*/