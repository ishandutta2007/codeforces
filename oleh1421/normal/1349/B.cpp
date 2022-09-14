#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const ll mod=1000000000+7;
const int N=100010;
int a[N];
int s[N];
int s1[N];
void solve(){
    int n,k;cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    if (n==1){
        if (a[1]==k){
            cout<<"yes\n";
        } else {
            cout<<"no\n";
        }
        return;
    }
    a[0]=a[n+1]=0;
    bool ok=false;
    for (int i=1;i<=n;i++){
        if (a[i]==k) ok=true;
        if (a[i]>=k) s[i]=s[i-1]+1;
        else s[i]=s[i-1]-1;
    }
    if (!ok){
        cout<<"no\n";
        return;
    }
    int mn=1000000001;
    for (int i=1;i<=n;i++){
        if (s[i]-mn>0){
            cout<<"yes\n";
            return;
        }
        mn=min(mn,s[i-1]);
    }
    cout<<"no\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}