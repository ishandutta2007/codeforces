#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const ll mod=1000000007ll;
const int N=80010;
int a[N];
int s[N];
bool ok[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=0;i<n;i++) s[i+1]=a[i+1],s[i+1]+=s[i];
    for (int i=0;i<=n;i++) ok[i]=false;
    int res=0;
    for (int l=0;l<n;l++){
        for (int r=l+2;r<=n && s[r]-s[l]<=n;r++){
            ok[s[r]-s[l]]=true;
        }
    }
    for (int i=1;i<=n;i++) res+=ok[a[i]];
    cout<<res<<endl;


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