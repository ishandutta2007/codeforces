//#pragma GCC opitmize ("trapv")
//#pragma GCC opitmize ("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=300010;
int a[N];
int c[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    c[1]=1;
    for (int i=2;i<=n;i++){
        if (a[i]==a[i-1]) c[i]=c[i-1];
        else c[i]=(c[i-1]^3);
    }
    if (a[1]!=a[n] && c[1]==c[n]){
        int pos=-1;
        for (int i=1;i<n;i++){
            if (a[i]==a[i+1]){
                pos=i;
                break;
            }
        }
        if (pos==-1) c[n]=3;
        else {
            for (int i=pos+1;i<=n;++i) c[i]^=3;
        }
    }
    int maxx=0;
    for (int i=1;i<=n;i++) maxx=max(maxx,c[i]);
    cout<<maxx<<endl;;
    for (int i=1;i<=n;i++) cout<<c[i]<<" ";
    cout<<endl;
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

/*
10 7
1 1 1 3 3 3 35 40 40 40
*/