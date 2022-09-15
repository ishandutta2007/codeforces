
#include <bits/stdc++.h>
using namespace std;
int s[10001];
int d[10001];
int a[10001];
int main() {
    int n,t;cin>>n>>t;
    for (int i=1;i<=n;i++) cin>>s[i]>>d[i];
    for (int i=1;i<=n;i++){
        if (s[i]>=t) a[i]=s[i];
        else {
            a[i]=((t-s[i])/d[i]+((t-s[i])%d[i]>0))*d[i]+s[i];
        }
    }
    int index=1;
    for (int i=2;i<=n;i++) if (a[i]<a[index]) index=i;
    cout<<index;
    return 0;
}