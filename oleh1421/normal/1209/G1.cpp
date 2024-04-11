//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
#define int long long
using namespace std;
int a[300001];
int l[300001];
int r[300001];
int cnt[300001];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,tt;cin>>n>>tt;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        if (!l[a[i]]) l[a[i]]=i;
        r[a[i]]=i;
        cnt[a[i]]++;
    }
    int res=0;
    vector<int>v;
    int last=0;
    int T=1;
    for (int i=1;i<=T && i<=n;i++){
        T=max(T,r[a[i]]);
        v.push_back(a[i]);
        if (T==i){
            int maxx=0;
            for (auto to:v) maxx=max(maxx,cnt[to]);
            res+=(i-last)-maxx;
            v.clear();
            last=T;
            T++;
        }
    }
    cout<<res;
    return 0;
}
/*
0011
0101
1110
1111

*/