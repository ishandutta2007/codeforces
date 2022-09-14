//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=510;
const int A=1000001;
const ll mod=1000000007ll;
//#define int ll
const int inf=1000000001;
int a[N][N];
int d[N];
void solve(){
    int n;cin>>n;
    if (n%2){
        int x=(n-1)/2;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                a[i][j]=-1;
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=x;j++){
                int nxt=(i+j);
                if (nxt>n) nxt-=n;
                a[i][nxt]=1;
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                cout<<a[i][j]<<" ";
            }
        }
        cout<<endl;
        return;
    }
    int x=(n-1)/2;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            a[i][j]=-1;
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=x;j++){
            int nxt=(i+j);
            if (nxt>n) nxt-=n;
            a[i][nxt]=1;
        }
        int nxt=(i+x+1);
        if (nxt>n) nxt-=n;
        a[i][nxt]=a[nxt][i]=0;
    }
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            cout<<a[i][j]<<" ";
        }
    }
    cout<<endl;
    return;

//    n|n(n-1)/2+2*x

//    n/2
//    2*2+4*3=



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


/**
1 2 3 1 2 3
3 2 1 3 2 1
1 2 4 5 2 3 5 1 2 3 4 5
5 4 3 2 1 5 4 3 2 1 5 4 3 2 1
**/
//30
//9 10
//x(x+1)/(2*n)
///6778 5734
/*
11*x 13*a
11*y 13*b
*/
//11 14641 28561 13