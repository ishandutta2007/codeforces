#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200010;
int type[N];
int ind[N];
int p[N];
void solve(){
    int n;cin>>n;
    vector<int>v;
    int cn=0;
    for (int i=1;i<=n*2;i++){
        char c;cin>>c;
        if (c=='+'){
            ind[i]=++cn;
            type[i]=0;
            v.push_back(cn);
        } else {
            int x;cin>>x;
            type[i]=1;
            if (v.empty()){
                cout<<"NO\n";
                return;
            }
            p[v.back()]=x;
            ind[i]=x;
            v.pop_back();
        }
    }
    set<int>st;
    for (int i=1;i<=n*2;i++){
        if (type[i]==0) st.insert(p[ind[i]]);
        else {
            if (st.empty() || (*st.begin())!=ind[i]){
                cout<<"NO\n";
                return;
            }
            st.erase(st.begin());
        }
    }
    cout<<"YES\n";
    for (int i=1;i<=n;i++) cout<<p[i]<<" ";
    cout<<endl;


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