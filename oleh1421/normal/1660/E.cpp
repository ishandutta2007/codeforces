#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N=3010;
const ll mod=998244353;
const ll inf=2000000000000000001;
int a[N][N];
void solve(){
    int n;cin>>n;
    int sum=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            char c;cin>>c;
            a[i][j]=(c-'0');
            sum+=a[i][j];
        }
    }
    int res=0;
    for (int add=0;add<n;add++){
        int cur=0;
        for (int i=0;i<n;i++){
            cur+=a[i][(i+add)%n];
        }
        res=max(res,cur);
    }
    cout<<sum+n-2*res<<endl;



}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}