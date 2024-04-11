#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
typedef long long ll;
using namespace std;
int a[300001];
int L[300001];
int last[300001];
int s[300001];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    for (int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    L[0]=1;
    for (int i=1;i<=n;i++){
        L[i]=max(L[i-1],last[a[i]]+1);
        last[a[i]]=i;
    }
    int res=0;
    for (int i=1;i<=n;i++){
        if (a[i]>1) continue;
        int j=i+1;
        int maxx=a[i];
        while (j<=n && a[j]>1){
             maxx=max(maxx,a[j]);
             if (j-maxx+1>=L[j] && s[j]-s[j-maxx]==maxx*(maxx+1)/2) res++;
             j++;
        }
    }
    for (int i=1;i<=n;i++){
        s[i]=0;
        L[i]=0;
        last[i]=0;
    }
    reverse(a+1,a+n+1);
    for (int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    L[0]=1;
    for (int i=1;i<=n;i++){
        L[i]=max(L[i-1],last[a[i]]+1);
        last[a[i]]=i;
    }
    for (int i=1;i<=n;i++){
        if (a[i]>1) continue;
        res++;
        int j=i+1;
        int maxx=a[i];
        while (j<=n && a[j]>1){
             maxx=max(maxx,a[j]);
             if (j-maxx+1>=L[j] && s[j]-s[j-maxx]==maxx*(maxx+1)/2) {
                res++;
             }
             j++;
        }
    }
    cout<<res;
    return 0;
}