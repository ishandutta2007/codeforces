//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const int N=1000010;
int a[N],b[N];
int pr[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i],a[i]=i-a[i];
    for (int i=1;i<=n;i++) cin>>b[i],b[i]+=i;
    b[0]=0;
    queue<int>q;
    q.push(n);
    pr[n]=n+1;
    set<int>st;
    for (int i=0;i<n;i++) st.insert(i),pr[i]=-1;
    while (!q.empty()){
        int s=b[q.front()];
        auto itL=st.lower_bound(a[s]);
        auto itR=st.upper_bound(s);
        vector<int>del;
        for (auto it=itL;it!=itR;it++){
            int to=(*it);
            pr[to]=q.front();
            q.push(to);
            del.push_back(to);
        }
        for (int x:del) st.erase(x);
        q.pop();
    }
    if (pr[0]==-1){
        cout<<-1<<endl;
        return;
    }
    int cur=0;
    vector<int>ans;
    while (cur<n){
        ans.push_back(cur);
        cur=pr[cur];
    }
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for (int i:ans) cout<<i<<" ";
    cout<<endl;
//    b[a[p]],b[a[p]+1],...,b[p]

}
int32_t  main()
{
//    cout<<mod<<endl;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
/**
5
1
1
2
1
0
2
4
0
1
4

**/