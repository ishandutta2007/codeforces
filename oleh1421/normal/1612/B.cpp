//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const int N=160000;
const ll mod=998244353;
int p[N];
void solve(){
    int n,a,b;cin>>n>>a>>b;
    for (int i=1;i<=n;i++) p[i]=0;
    p[1]=a;
    p[n/2+1]=b;
    int mx=n;
    for (int i=1;i<=n;i++){
        if (p[i]) continue;
        while (mx==a || mx==b) mx--;
        p[i]=mx;
        mx--;
    }
    int mn=n+1;
    mx=0;
    for (int i=1;i<=n/2;i++) mn=min(mn,p[i]);
    for (int i=1;i<=n/2;i++) mx=max(mx,p[i+n/2]);
    if (a!=mn || b!=mx){

        cout<<-1<<endl;
        return;
    }
    for (int i=1;i<=n;i++) cout<<p[i]<<" ";
    cout<<endl;
//    if (a>n/2+1 || b<n/2){
//        cout<<-1<<endl;
//        return;
//    }
//    for (int i=n;i>=n/2+2;i--) cout<<i<<" ";
//    cout<<a<<" ";
//    cout<<b<<" ";
//    for (int i=1;i<=n/2+1;i++){
//        if (i==a || i==b) continue;
//        cout<<i<<" ";
//    }
//    cout<<endl;
}
int32_t  main()
{
//    cin>>X>>Y;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}

/**
11 3
1 2
2 3
3 4
4 5
5 6
6 7
4 8
8 9
9 10
10 11
**/