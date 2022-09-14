//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const ll mod=1000000007;
const int N=500001;
int a[N][5];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        for (int j=0;j<5;j++) cin>>a[i][j];
    }
    for (int i=0;i<5;i++){
        for (int j=i+1;j<5;j++){
            int ok_i=0,ok_j=0,ok_ij=0;
            for (int t=1;t<=n;t++){
                if (a[t][i] && a[t][j]) ok_ij++;
                else if (a[t][i]) ok_i++;
                else if (a[t][j]) ok_j++;
            }
            if (ok_i+ok_ij+ok_j<n){
                continue;
            }
            if (ok_i*2<=n && ok_j*2<=n){
                cout<<"YES\n";
                return;
            }
        }
    }
    cout<<"NO\n";
}
int32_t  main()
{
//    cout<<mod<<endl;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}

//a b c
//a (b+c)/2 (b+c)/2
//(2*a+b+c)/4 (2*a+b+c)/4 (b+c)/2
//(2*a+b+c)/4 (2*a+3*b+3*c)/8 (2*a+3*b+3*c)/8
//(6*a+5*b+5*c)/16 (6*a+5*b+5*c)/16
///C=MEX(A)^B + MEX(B)^A
///MEX(C)=MEX(A)^MEX(B)
///A - DONE
//a b c
//a b c d

//0 1 2 3

//0 1 2 3
//0 1 2 3
//
//1+1+1+1+

/**
1 3
0.0 0.1 0.5 0.2
**/