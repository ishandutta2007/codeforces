#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const long long mod=991987651ll;
int c[1010];
int a[1010];
int suf[1010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,d;cin>>n>>m>>d;
    for (int i=1;i<=m;i++) cin>>c[i];
    suf[m+1]=0;
    for (int i=m;i>=1;i--) suf[i]=(suf[i+1]+c[i]);
    int pos=0;
    for (int i=1;i<=m;i++){
        int nxt=min(pos+d,n+1-suf[i]);
        for (int j=nxt;j<=nxt+c[i]-1;j++) a[j]=i;
        nxt+=c[i]-1;
        pos=nxt;
    }
    if (pos+d<=n){
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    for (int i=1;i<=n;i++) cout<<a[i]<<" ";
    return 0;
}