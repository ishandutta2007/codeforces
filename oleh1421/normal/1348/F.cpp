#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;
int l[N];
int r[N];
int p[N];
int q[N];
vector<pair<int,int> >g[N];
int t[N];
void upd(int n,int pos,int x){
    for (;pos<=n;pos|=pos+1) t[pos]+=x;
}
int get(int pos){
    int sum=0;
    for (;pos>0;pos&=pos+1,pos--) sum+=t[pos];
    return sum;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    vector<pair<int,int> >v;
    for (int i=1;i<=n;i++) cin>>l[i]>>r[i],g[l[i]].push_back({r[i],i});
    set<pair<int,int> >st;
    for (int i=1;i<=n;i++){
        for (auto cur:g[i]){
            st.insert(cur);
        }
        int ind=(*st.begin()).second;
        p[ind]=i;
        st.erase(st.begin());
        if (!st.empty()){
            v.push_back({ind,(*st.begin()).second});
        }
    }

    for (auto cur:v){
        int i=cur.first;
        int j=cur.second;
        if (p[j]>=l[i] && p[j]<=r[i] && p[i]>=l[j] && p[i]<=r[j]){
            cout<<"NO\n";
            for (int t=1;t<=n;t++) cout<<p[t]<<" ";
            cout<<endl;
            swap(p[i],p[j]);
            for (int t=1;t<=n;t++) cout<<p[t]<<" ";
            cout<<endl;
            return 0;
        }
    }
    cout<<"YES\n";
    for (int t=1;t<=n;t++) cout<<p[t]<<" ";
    cout<<endl;

    return 0;
}