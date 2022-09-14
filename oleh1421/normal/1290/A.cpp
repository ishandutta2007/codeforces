#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define endl '\n'
const int N=300010;
int a[N];
void solve(){
    int n,m,k;cin>>n>>m>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    k=min(k,m-1);
    int maxx=-1;
    for (int i=0;i<=k;i++){
        int minx=1000000001;
        for (int j=0;j<m-k;j++){
            int cur=max(a[i+j+1],a[n+i+j+1-m]);
            minx=min(minx,cur);
        }
        maxx=max(maxx,minx);
    }
    cout<<maxx<<endl;;
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}