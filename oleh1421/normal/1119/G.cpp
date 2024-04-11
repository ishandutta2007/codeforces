#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=1000001;
pair<int,int> hp[N];
vector<int>ans[N];
int a[N];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m;
    ll sum=0ll;
    for (int i=1;i<=m;i++) cin>>hp[i].first,hp[i].second=i,sum+=hp[i].first,hp[i].first*=-1;
    set<pair<int,int> >st;
    for (int i=1;i<=m;i++) st.insert(hp[i]);
    int t=(sum+n-1)/n;
    for (int i=1;i<=m;i++){
        if (!n) continue;
        int x=1;
        for (int j=20;j>=0;j--){
            if (x+(1<<j)>n) continue;
            ll sum=0;
            for (auto cur:st) {
                int val=-cur.first;
                if (val<x+(1<<j)) break;
                sum+=(val/(x+(1<<j)));
                if (sum>=t) break;
            }
            if (sum>=t) x+=(1<<j);
        }
        if (i==m) x=n;
        n-=x;
        a[i]=x;
        for (int j=1;j<=t;j++){
            if (st.empty()) break;
            auto cur=(*st.begin());
            st.erase(st.begin());
            ans[i].push_back(cur.second);
            cur.first+=x;
            if (cur.first<0) st.insert(cur);
        }
    }
    cout<<t<<endl;
    for (int i=1;i<=m;i++) cout<<a[i]<<" ";
    cout<<endl;
    for (int i=0;i<t;i++){
        for (int j=1;j<=m;j++){
            if (i<ans[j].size()) cout<<ans[j][i]<<" ";
            else cout<<"1 ";
        }
        cout<<endl;
    }
    return 0;
}