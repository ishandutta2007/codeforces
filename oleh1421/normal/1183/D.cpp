#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
typedef long long ll;
using namespace std;
int a[200001];
int cnt[200001];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        set<int>st;
        int n;cin>>n;
        for (int i=1;i<=n;i++){
            int a;cin>>a;
            cnt[a]++;
            st.insert(a);
        }
        vector<int>v;
        for (auto i:st){
            v.push_back(cnt[i]);
            cnt[i]=0;
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        int sum=0;
        int last=1000000001;
        for (int i=0;i<v.size();i++){
            v[i]=min(v[i],last-1);
            if (v[i]<=0) break;
            sum+=v[i];
            last=v[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}