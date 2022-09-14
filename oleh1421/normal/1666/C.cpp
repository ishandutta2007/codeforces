#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(vec) vec.begin(),vec.end()
#define endl '\n'
vector< pair< pair<int,int> ,pair<int,int> > > ans;

void solve(){
    pair<int,int> a[3];
    for(int i = 0;i<3;++i)
        cin>>a[i].first>>a[i].second;
    sort(a,a+3);
    if (a[0].first!=a[1].first) {
        ans.push_back({a[0], {a[1].first, a[0].second}});
    }
    if (a[0].second!=a[1].second){
        ans.push_back({{a[1].first,a[0].second},{a[1].first,a[1].second}});
    }
    if (a[1].first!=a[2].first){
        ans.push_back({{a[1].first,a[2].second},a[2]});
    }
    if (a[2].second<min(a[0].second,a[1].second)){
        ans.push_back({{a[1].first,min(a[0].second,a[1].second)}, {a[1].first,a[2].second}});
    }
    if (a[2].second>max(a[0].second,a[1].second)){
        ans.push_back({{a[1].first,max(a[0].second,a[1].second)},{a[1].first,a[2].second}});
    }
    cout<<ans.size()<<endl;
    for(auto [a,b]:ans)
        cout<<a.first<<' '<<a.second<<' '<<b.first<<' '<<b.second<<endl;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--)
        solve();
    return 0;
}