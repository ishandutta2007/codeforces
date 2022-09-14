#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=1000100;
const ll mod=998244353;

void solve(){
    int n,m,k;cin>>n>>m>>k;
    int rem=n%m;
    int shift=((n+m-1)/m)*rem;
    int start=0;
    for (int i=1;i<=k;i++){
        for (int j=0;j<rem;j++){
            cout<<((n+m-1)/m)<<" ";
            for (int t=0;t<((n+m-1)/m);t++) cout<<(start++)%n+1<<" ";
            cout<<endl;
        }
        for (int j=rem;j<m;j++){
            cout<<n/m<<" ";
            for (int t=0;t<n/m;t++) cout<<(start++)%n+1<<" ";
            cout<<endl;
        }
        start+=shift;
        start%=n;
    }
    cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
//A[j] - >
//(a+b1)%M+(b2+c)%M<(a+c)%M