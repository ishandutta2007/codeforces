#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
//#define int long long
#define MINX(a,b) if (a>b) a=b;
#define MAXX(a,b) if (a<b) a=b;
#define endl '\n'
typedef long long ll;
using namespace std;
int a[1000001];
int pos[1000001];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    vector<int>v;
    for (int i=1;i<n;i++){
        v.push_back(a[i]-a[i+1]);
    }
    sort(v.begin(),v.end());
    //reverse(v.begin(),v.end());
    ll res=a[n]-a[1];
    for (int i=0;i<k-1;i++) res+=v[i];
    cout<<res;
    return 0;
}
/*
6 3
18 75 245 847 1859 26
*/