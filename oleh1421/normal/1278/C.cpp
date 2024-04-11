#include <bits/stdc++.h>
#define endl '\n'
const long long mod=1000000007ll;
typedef long long ll;
using namespace std;
int a[1000001];
int pref[1000001];
int suf[1000001];
int maxx[1000001];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n+n;i++) cin>>a[i];
    pref[0]=0;
    for (int i=1;i<=n;i++) pref[i]=pref[i-1]+(a[i]==1);
    suf[n+n+1]=0;
    for (int i=n+n;i>n;i--) suf[i]=suf[i+1]+(a[i]==1);
    for (int i=1;i<=n;i++){
        maxx[i-pref[i]-pref[i]+n]=i;
    }
    int minx=n+n;
    for (int i=n+1;i<=n+n+1;i++){
        int cur=suf[i]+suf[i]-(n+n-i+1)+n;
        if (cur==n) minx=min(minx,i-1);
        if (!maxx[cur]) continue;
        minx=min(minx,i-maxx[cur]-1);
    }
    cout<<minx<<endl;
    for (int i=0;i<=n+n+n;i++) maxx[i]=0,pref[i]=0,suf[i]=0;

}
int main()
{
    //freopen("meetings.in","r",stdin);
    //freopen("meetings.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/*
5
2 1 1 1 2 2 1 1 1 1
*/