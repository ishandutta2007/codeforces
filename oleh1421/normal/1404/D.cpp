#include <bits/stdc++.h>
typedef long long ll;
//#define endl '\n'
using namespace std;
const int N=1000010;
int a[N];
int b[N];
int x[N];
int y[N];
vector<int>g[N];
bool used[N];
int mask[N];
vector<int>G[N];

int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);

    int n;cin>>n;
    if (n%2==0){
        cout<<"First\n";
        for (int i=1;i<=n;i++) cout<<i<<" ";
        for (int i=1;i<=n;i++) cout<<i<<" ";
        cout<<endl;
        int res;cin>>res;
        return 0;
    }
    cout<<"Second\n";
    for (int i=1;i<=n+n;i++){
        int x;cin>>x;
        if (a[x]) b[x]=i;
        else a[x]=i;
    }
    for (int i=1;i<=n;i++){
        if (a[i]>b[i]) swap(a[i],b[i]);
        x[i]=a[i]%n;
        y[i]=b[i]%n;
        g[x[i]].push_back(i);
        g[y[i]].push_back(i+n);
    }
    set<int>st;
    for (int i=0;i<n;i++) st.insert(i);
    int cur=0;
    for (int it=0;it<n;it++){
        st.erase(cur);
        int nxt=cur;
//        cout<<cur<<endl;
        for (int p:g[cur]){
            if (!used[p]){
                if (p<=n){
                    used[p]=used[p+n]=true;
                    nxt=y[p];
                    mask[p]=0;
                } else {
                    used[p-n]=used[p]=true;
                    nxt=x[p-n];
                    mask[p-n]=1;
                }
                break;
            }
        }
        if (st.find(nxt)==st.end()) {
            nxt=(*st.begin());
        }
        cur=nxt;
    }
    ll sum=0ll;
    for (int i=1;i<=n;i++){
        if (mask[i]) sum+=b[i];
        else sum+=a[i];
    }
    if (sum%(n+n)){
        for (int i=1;i<=n;i++) mask[i]^=1;
    }
    vector<int>ans;
    for (int i=1;i<=n;i++){
        if (mask[i]) ans.push_back(b[i]);
        else ans.push_back(a[i]);
    }
    sort(ans.begin(),ans.end());
    for (int i:ans) cout<<i<<" ";
    cout<<endl;
    int res;cin>>res;
    return 0;
}