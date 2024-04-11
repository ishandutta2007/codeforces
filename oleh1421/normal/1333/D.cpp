#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int N=3010;
int a[N];
int f[N];
void solve(){
    int n,k;cin>>n>>k;
    for (int i=1;i<=n;i++){
        char c;cin>>c;
        a[i]=(c=='L');
    }
    int cnt0=0;
    ll sum=0ll;
    vector<pair<int,int> >v;
    int maxx=0;
    for (int i=1;i<=n;i++){
        cnt0+=1-a[i];
        sum+=cnt0*a[i];
        f[i]=cnt0*a[i];
    }
    if (sum<k){
        cout<<-1<<endl;
        return;
    }
    vector<vector<int> >ans;
    while (k>0 && sum!=k){
        int cnt=0;
        vector<int>v;
        int ind=1;
        while (a[ind]) ind++;
        for (int j=ind;j<=n;j++){
            if (a[j]==1 && a[j-1]==0) v.push_back(j-1);
        }
        if (v.empty()) break;
        if (v.size()>=sum-k+1){
            vector<int>cur;
            for (int j=0;j<sum-k+1;j++){
                cur.push_back(v[j]);
                swap(a[v[j]],a[v[j]+1]);
            }
            ans.push_back(cur);
            sum-=sum-k+1;
            k--;
        } else {
            for (int j=0;j<v.size();j++){
                swap(a[v[j]],a[v[j]+1]);
            }
            ans.push_back(v);
            sum-=(int)v.size();
            k--;
        }
    }
    if (sum!=k){
        cout<<-1<<endl;
        return;
    }

    int ind=1;
    while (a[ind]) ind++;
    for (int i=ind;i<=n;i++){
        if (!a[i]) continue;
        int j=i;
//        cout<<i<<endl;
        while (j-1>0 && !a[j-1]){
            swap(a[j-1],a[j]);
            ans.push_back({j-1});
            j--;
        }
    }
    for (auto cur:ans){
        cout<<cur.size()<<" ";
        for (auto x:cur) cout<<x<<" ";
        cout<<endl;
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}