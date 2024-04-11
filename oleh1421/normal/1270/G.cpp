//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=1000010;
int a[N];
bool used[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        used[i]=false;
        cin>>a[i];
        a[i]=i-a[i];
    }
    int cur=1;
    while (!used[cur]){
        used[cur]=true;
        cur=a[cur];
    }
    int st=cur;
    vector<int>ans;
    ans.push_back(st);
    cur=a[cur];
    while (cur!=st){
        ans.push_back(cur);
        cur=a[cur];
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for (int i:ans) cout<<i<<" ";
    cout<<endl;
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
/*

3 0
aa
bcd
*/