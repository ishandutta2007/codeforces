#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
#define int ll
using namespace std;
using namespace __gnu_pbds;
template<class T>using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const int N=1000100;
pair<ll,int>a[N];
ll f(int l,int r){
    int cnt=a[r].second-a[l-1].second;
    return a[r].first-a[r-cnt].first;
}
ll ans[N];
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,q;cin>>n>>m>>q;
    vector<pair<int,int> >v;
    int Cnt=0;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        a[++Cnt]={x,1};
    }
    for (int i=1;i<=m;i++){
        int x;cin>>x;
        a[++Cnt]={x,0};
    }
    sort(a+1,a+Cnt+1);
    vector<pair<ll,int> >d;
    for (int i=2;i<=Cnt;i++){
        d.push_back({a[i].first-a[i-1].first,i});
    }
    sort(d.begin(),d.end());
    for (int i=1;i<=Cnt;i++){
        a[i].first+=a[i-1].first;
        a[i].second+=a[i-1].second;
    }
    set<pair<int,int> >st;
    ll res=0ll;
    for (int i=1;i<=Cnt;i++){
        st.insert({i,i});
        res+=f(i,i);

    }
    vector<pair<int,int> >Q;
    for (int i=1;i<=q;i++){
        int k;cin>>k;
        Q.push_back({k,i});
    }
    sort(Q.begin(),Q.end());
    int j=0;
    for (auto cur:Q){
//        cout<<cur.first<<endl;
        while (j<d.size() && d[j].first<=cur.first){
//            cout<<"U "<<d[j].second<<endl;
            auto it=st.upper_bound({d[j].second,0});
            auto del=(*it);
            int r=(*it).second;
            res-=f((*it).first,(*it).second);
            it--;
            int l=(*it).first;
            res-=f((*it).first,(*it).second);
            res+=f(l,r);
            st.erase(it);
            st.erase(st.find(del));
            st.insert({l,r});
            j++;
        }
        ans[cur.second]=res;
    }
    for (int i=1;i<=q;i++) cout<<ans[i]<<endl;

    return 0;

}
/**
10 30 15
12 31 14 18

10 12 14 15 18 30 31
**/