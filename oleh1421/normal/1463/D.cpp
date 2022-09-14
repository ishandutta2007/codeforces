
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=500010;
const ll mod=1000000007ll;
int a[N],b[N];
bool used[N];
int l[N];
int l1[N];
void solve(){
    int n;cin>>n;
    set<int>st;
    for (int i=1;i<=n*2;i++) used[i]=false;
    for (int i=1;i<=n;i++){
        cin>>b[i];
        used[b[i]]=true;
    }
    int cn=0;
    for (int i=1;i<=n+n;i++){
        if (!used[i]) a[++cn]=i;
    }
    int mx=0;
    int R=n;
    for (int i=1;i<=n;i++){
        l[i]=lower_bound(b+1,b+n+1,a[i])-b;
        mx=max(mx+1,l[i]);
        if (mx>n){
            R=i-1;
            break;
        }
    }
    int mx1=0;
    int L=0;
    for (int i=1;i<=n;i++){
        l1[i]=lower_bound(a+1,a+n+1,b[i])-a;
        mx1=max(mx1+1,l1[i]);
        if (mx1>n){
            L=n-i+1;
            break;
        }
    }
//    cout<<L<<" "<<R<<endl;
    if (L>R) cout<<"0\n";
    else cout<<R-L+1<<"\n";

}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}
//1
//2
//3 1 5 4 2 2
//3 1 1
//1 4 5 9 10
//2 3 6 7 8
//4