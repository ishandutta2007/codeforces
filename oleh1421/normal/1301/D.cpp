#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=450010;
vector<pair<int,string> >v;
vector<pair<int,string> >ans;
void solve(int n,int m,int k){
    for (int i=1;i<n;i++){
        v.push_back({m-1,"RDU"});
        v.push_back({m-1,"L"});
        v.push_back({1,"D"});
    }
    v.push_back({m-1,"R"});
    v.push_back({m-1,"L"});
    v.push_back({n-1,"U"});
}
int32_t main()
{
//    freopen("repair.in","r",stdin);
//    freopen("repair.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,k;cin>>n>>m>>k;
    if (4*n*m-2*n-2*m<k){
        cout<<"NO\n";
        return 0;
    }
    solve(n,m,k);
    for (int i=0;i<v.size() && k>0;i++){
        if (!v[i].first) continue;
        if (v[i].first*(int)v[i].second.size()<=k){
            k-=v[i].first*(int)v[i].second.size();
            ans.push_back(v[i]);
        } else {
            if ((k/(int)v[i].second.size())) ans.push_back({(k/(int)v[i].second.size()),v[i].second});
            string add="";
            for (int j=0;j<(k%(int)v[i].second.size());j++) add+=v[i].second[j];
            if (!add.empty()) ans.push_back({1,add});
            k=0;
        }
    }
    cout<<"YES\n";
    cout<<ans.size()<<endl;
    for (auto cur:ans) cout<<cur.first<<" "<<cur.second<<endl;
    return 0;

}