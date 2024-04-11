#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500500;
int p[N];
int pos[N];
int a[N];
int val[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i],pos[p[i]]=i;
    for (int i=1;i<=n;i++) a[i]=val[i]=0;
    int last=-1;
    int R=n;
    for (int i=1;i<=n;i++){
        if (last!=-1 && pos[i]!=last+1){
            cout<<"No\n";
            return;
        }
        if (pos[i]==R){
            R=n-i;
            last=-1;
        } else{
            last=pos[i];
        }

    }
    cout<<"Yes\n";
}
int32_t main()
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