#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
//#define int long long
typedef long long ll;
using namespace std;
int a[200005];
int32_t main() {
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int res=0;
    for (int i=2;i<n;i++){
        if (a[i]<a[i-1] || a[i]<a[i+1]) continue;
        set<int>setik;
        for (int j=i+1;j<=n && a[j]<a[i];j++) setik.insert(a[j]);
        for (int j=i-1;j>=1 && a[j]<a[i];j--) if (setik.find(a[i]-a[j])!=setik.end()) res++;
    }
    cout<<res;

    return 0;
}