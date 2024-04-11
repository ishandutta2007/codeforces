//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=300010;
mt19937 rnd(time(nullptr));
int a[N];
int cnt[1000100];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n+n;i++) cin>>a[i];
    sort(a+1,a+n+n+1);
    for (int it=1;it<n+n;it++){
        for (int i=1;i<=n+n;i++) cnt[a[i]]=0;
        for (int i=1;i<=n+n;i++) cnt[a[i]]++;
        vector<pair<int,int> >ans;
        ans.push_back({a[it],a[n+n]});
        int mx=a[n+n];
        cnt[mx]--;
        cnt[a[it]]--;
        bool ok=true;
        for (int i=1;i<n;i++){
            int last=mx;
            while (!cnt[mx]) mx--;
            cnt[mx]--;
            if (cnt[last-mx]==0){
                ok=false;
                break;
            }
            ans.push_back({last-mx,mx});
            cnt[last-mx]--;
        }
        for (int i=1;i<=n+n;i++) cnt[a[i]]=0;

        if (ok){
            cout<<"YES\n";
            cout<<a[it]+a[n+n]<<endl;
            for (auto cur:ans){
                cout<<cur.first<<" "<<cur.second<<endl;
            }
            return;
        }
    }
    cout<<"NO\n";

}
int32_t main()
{
//
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}

//4 1 2 3
//3 1 2 4
//2 1 3 4
//1 2 3 4
//2 3 1
//a[i]-a[i-1]+a[i-2]-a[i-3]+...