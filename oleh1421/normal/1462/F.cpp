
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=500010;
const ll mod=1000000007ll;
int l[N],r[N];
map<int,int>mp;
int t[N];
void upd(int n,int pos,int x){
    for (;pos<=n;pos|=pos+1){
        t[pos]+=x;
    }
}
int get(int pos){
    int cnt=0;
    for (;pos>=0;pos&=pos+1,pos--) cnt+=t[pos];
    return cnt;
}
void solve(){
    mp.clear();
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>l[i]>>r[i];
    set<int>st;
    for (int i=1;i<=n;i++){
        st.insert(l[i]);
        st.insert(r[i]);
    }
    st.insert(0);
    int cur=0;
    for (int x:st){
        mp[x]=cur++;
    }
    vector<pair<int,int> >v;
    for (int i=1;i<=n;i++) l[i]=mp[l[i]],r[i]=mp[r[i]],v.push_back({r[i],l[i]});
    sort(v.begin(),v.end());
    for (int i=1;i<=n;i++) upd(cur,l[i],1);
    int res=0;
    for (int i=0;i<v.size();i++){
        upd(cur,v[i].second,-1);
        pair<int,int>fnd={v[i].second,-1};
        int pos=lower_bound(v.begin(),v.end(),fnd)-v.begin();
        int cur=i-pos+1+get(v[i].first);
        res=max(res,cur);
    }
    cout<<n-res<<endl;
}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}
//3 1 5 4 2 2
//3 1 1