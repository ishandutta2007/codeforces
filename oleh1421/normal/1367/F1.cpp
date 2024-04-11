//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef unsigned long long ll;
#define endl '\n'
typedef long double ld;
//#define double ld
using namespace std;
const int N=300010;
int a[N];
int b[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i],b[i]=a[i];
    sort(b+1,b+n+1);
    b[n+1]=-1;
    int mx=0;
    for (int i=1;i<=n;i++){
        int pos=i;
        for (int j=1;j<=n;j++){
            if (a[j]==b[pos]) pos++;
        }
        mx=max(mx,pos-i);
    }
    cout<<n-mx<<endl;

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
/*
1
abba
3
1 0 1
*/