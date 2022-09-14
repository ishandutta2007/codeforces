//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
///#define int ll
#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const int N=2000100;
const ll mod=1000000007;

void solve(){
    int n;cin>>n;
    vector<int>a(n+1,0),cnt(n+1,0),cnt1(n+1,0);
    for (int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    int cur=-1;
    vector<int>ans;
    set<int>st;
    for (int i=1;i<=n;i++){
        if (i==1 || cnt[cur]==0){
            if (i!=1) ans.push_back(cur);
            cur=0;
            for (int x:st) cnt1[x]=0;
            st.clear();

        }
        st.insert(a[i]);
        cnt1[a[i]]++;
        cnt[a[i]]--;
        while (cnt1[cur]) cur++;
    }
    ans.push_back(cur);
    cout<<ans.size()<<endl;
    for (int i:ans) cout<<i<<" ";
    cout<<endl;
}

int32_t  main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**
1
3
c
baa
abc


abc
b
a
**/