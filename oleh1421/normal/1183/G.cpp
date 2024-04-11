#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
typedef long long ll;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        int n;cin>>n;
        vector<int>cnt(n+1,0);
        vector<int>cnt1(n+1,0);
        vector<vector<int> >type(n+1,vector<int>());
        for (int i=1;i<=n;i++){
            int a,f;cin>>a>>f;
            cnt[a]++;
            if (f) cnt1[a]++;
        }
        for (int i=1;i<=n;i++){
            type[cnt[i]].push_back(cnt1[i]);
        }
        multiset<int>cur;
        int res=0;
        int res1=0;
        for (int i=n;i>=1;i--){
            for (auto j:type[i]) cur.insert(j);
            if (!cur.empty()){
                res+=i;
                res1+=min((*cur.rbegin()),i);
                cur.erase(--cur.end());
            }
        }
        cout<<res<<" "<<res1<<endl;
    }
    return 0;
}