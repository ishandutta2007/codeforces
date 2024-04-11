//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=301019;
const ll mod=1000000007ll;
__int128_t x[N],y[N];
__int128_t dist(int i,int j){
    return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}
bool ok(int A,int B,int C){
    return (dist(A,B)+dist(B,C)>dist(A,C));
}
int p[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        p[i]=i;
        int a,b;cin>>a>>b;
        x[i]=a,y[i]=b;
    }
    for (int i=3;i<=n;i++){
        for (int j=i;j>=3;j--){
            if (!ok(p[j-2],p[j-1],p[j])) swap(p[j],p[j-1]);
        }
    }
    for (int i=3;i<=n;i++){
        if (!ok(p[i-2],p[i-1],p[i])){
            cout<<-1<<endl;
            exit(1);
            return;
        }
    }
    for (int i=1;i<=n;i++) cout<<p[i]<<" ";
    cout<<endl;
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
/*

*/