//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200010;
int a[N];
int t[N];
map<int,vector<int> >g;
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    set<int>X;
    for (int i=1;i<=n;i++) cin>>a[i],X.insert(a[i]),g[a[i]].push_back(i);
    for (int i=1;i<=n;i++) cin>>t[i];
    X.insert(2000000001);
    multiset<int>st;
    ll sum=0ll;
    ll res=0ll;
    for (int x:X){
        if (x==2000000001) break;
        int nxt=*(X.upper_bound(x));
        for (int i:g[x]){
            st.insert(t[i]);
            sum+=t[i];
        }
        int cnt=min(nxt-x,(int)st.size());
        for (ll i=0;i<cnt;i++){
            res+=(*st.rbegin())*i;
            sum-=(*st.rbegin());
            st.erase(--st.end());
        }
        res+=(nxt-x)*sum;
    }
    cout<<res<<endl;
    return 0;
}