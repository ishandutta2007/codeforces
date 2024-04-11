
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=1000100;
int dsu[N];
int d[N];
int prime[N];
int a[N];
vector<int>dv(int x){
    vector<int>ans;
    while (x>1){
        ans.push_back(d[x]);
        int cur=prime[d[x]];
//        cout<<x<<" "<<d[x]<<endl;
        while (x%cur==0) x/=cur;
    }
    return ans;
}
int get(int x){
    if (x==dsu[x]) return x;
    return dsu[x]=get(dsu[x]);
}
bool used[N];
void solve(){
    int cnt=0;
    for (int i=2;i<N;i++){
        if (d[i]) continue;
        prime[++cnt]=i;
        for (int j=i;j<N;j+=i) d[j]=cnt;
    }
//    for (int i=2;i<10;i++) cout<<prime[d[i]]<<" ";
//    cout<<endl;
    for (int i=1;i<=cnt;i++){
        dsu[i]=i;
    }
    int n,q;cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++){
        vector<int>pp=dv(a[i]);
        for (int i=1;i<pp.size();i++){
            int a=get(pp[0]);
            int b=get(pp[i]);
            if (a!=b) dsu[a]=b;
        }
    }
    set<pair<int,int> >st;
    for (int i=1;i<=n;i++){
        vector<int>x=dv(a[i]);
        vector<int>y=dv(a[i]+1);
        vector<int>v;
        for (int i:x){
            i=get(i);
            if (!used[i]){
                v.push_back(i);
                used[i]=true;
            }
        }
        for (int i:y){
            i=get(i);
            if (!used[i]){
                v.push_back(i);
                used[i]=true;
            }
        }
        for (int i:v) used[i]=false;
        for (int i=0;i<v.size();i++){
            for (int j=0;j<i;j++){
                st.insert({min(v[i],v[j]),max(v[i],v[j])});
            }
        }
    }
    for (int i=1;i<=q;i++){
        int s,t;cin>>s>>t;
        s=d[a[s]];
        t=d[a[t]];
        s=get(s);
        t=get(t);
        if (s>t) swap(s,t);
        if (s==t) cout<<0<<endl;
        else if (st.find({s,t})==st.end()) cout<<2<<endl;
        else cout<<1<<endl;
    }
}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }

    return 0;
}
//1 3 3 4
//0 1 2 3