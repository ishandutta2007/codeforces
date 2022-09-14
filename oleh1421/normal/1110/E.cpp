#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[1000001];
int b[1000001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    vector<int>u;
    vector<int>v;
    for (int i=2;i<=n;i++){
        u.push_back(a[i]-a[i-1]);
        v.push_back(b[i]-b[i-1]);
    }
    sort(u.begin(),u.end());
    sort(v.begin(),v.end());
    if (u==v && a[1]==b[1] && a[n]==b[n]) cout<<"Yes";
    else cout<<"No";
    return 0;
}
/*
6 3
18 75 245 847 1859 26
*/