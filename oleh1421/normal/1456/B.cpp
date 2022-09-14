//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=500010;
int a[N];
int get(int l,int r){
    return (a[r]^a[l-1]);
}
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    if (n>65){
        cout<<1<<endl;
        return;
    }
    for (int i=1;i<=n;++i) a[i]^=a[i-1];
    int res=1000000001;
    for (int i=1;i<=n;i++){
        for (int j=i;j<=n;j++){
            for (int t=j+1;t<=n;t++){
                if (get(i,j)>get(j+1,t)){
                    res=min(res,t-i-1);
                }
            }
        }
    }
    if (res>n) res=-1;
    cout<<res<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }

    return 0;
}