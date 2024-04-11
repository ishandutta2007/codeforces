#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
#define y1 y_1
const int N=500010;
int a[N];
int L[N];
int R[N];
ll f(ll n){
//    cout<<n<<" "<<n*n*(n+1ll)/2ll<<" "<<n*(n+1ll)*(n+n+1ll)/6ll<<endl;
    return (n+1ll)*n*(n+1ll)/2ll-n*(n+1ll)*(n+n+1ll)/6ll;
}
ll num_of_L[N];
ll num_of_R[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        char c;cin>>c;
        a[i]=(c-'0');
    }
    int cnt=0;
    int m=0;
    for (int i=1;i<=n;i++){
        if (a[i]) cnt++;
        else if (cnt){
            m++;
            L[m]=i-cnt;
            R[m]=i-1;
            cnt=0;
        }
    }
    if (cnt){
        m++;
        L[m]=n+1-cnt;
        R[m]=n;
        cnt=0;
    }
    ll res=0ll;

    vector<pair<int,int> >v;
    for (int i=1;i<=m;i++){
        for (ll j=1;j<R[i]-L[i]+1;j++){
            pair<int,int>fnd={-j,1000000001};
            int pos=upper_bound(v.begin(),v.end(),fnd)-v.begin();
            if (!pos) res+=j*(L[i]-1ll);
            else res+=j*(L[i]-(R[v[pos-1].second]-j+1ll)-1ll);
        }
        pair<int,int>fnd={-(R[i]-L[i]+1),1000000001};
        int pos=upper_bound(v.begin(),v.end(),fnd)-v.begin();
        if (!pos) num_of_L[i]=L[i]-1ll;
        else num_of_L[i]=(L[i]-(R[v[pos-1].second]-(R[i]-L[i]+1ll)+1ll)-1ll);
        pair<int,int>cur={-(R[i]-L[i]+1),i};
        while (!v.empty() && v.back().first>=cur.first) v.pop_back();
        v.push_back(cur);
    }
    v.clear();
    for (int i=m;i>=1;i--){
        for (ll j=1;j<R[i]-L[i]+1;j++){
            pair<int,int>fnd={-j,-1000000001};
            int pos=lower_bound(v.begin(),v.end(),fnd)-v.begin();
            if (!pos){
                res+=j*(n-R[i]+0ll);
            } else {
                res+=j*(L[v[pos-1].second]+j-R[i]-1ll);
            }
//            cout<<i<<" "<<j<<" "<<res-14<<endl;
        }
        pair<int,int>fnd={-(R[i]-L[i]+1),-1000000001};
        int pos=lower_bound(v.begin(),v.end(),fnd)-v.begin();
        if (!pos){
            num_of_R[i]=(n-R[i]+0ll);
        } else {
            num_of_R[i]=(L[v[pos-1].second]+(R[i]-L[i]+1ll)-R[i]-1ll);
        }
        pair<int,int>cur={-(R[i]-L[i]+1),i};
        while (!v.empty() && v.back().first>=cur.first) v.pop_back();
        v.push_back(cur);
    }
//    cout<<res-14<<endl;
    for (int i=1;i<=m;i++){
        res+=(R[i]-L[i]+1ll)*((num_of_L[i]+1ll)*(num_of_R[i]+1ll)-1ll);
    }
    for (int i=1;i<=m;i++){
        res+=f(R[i]-L[i]+1ll);
    }
    cout<<res<<endl;


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