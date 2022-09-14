#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const ll mod=1000000007ll;
const int N=510;
int f(int x,int n){
    return (x-(x/n));
}
void solve(){
    int n,k;cin>>n>>k;
    int res=2000000001;
    for (int i=31;i>=0;i--){
        if (res-(1<<i)<0) continue;
        if (f(res-(1<<i),n)>=k) res-=(1<<i);
    }
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