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
void solve(){
    int n;cin>>n;
    string s,t;cin>>s>>t;
    for (int i=0;i<n;i++){
        if (s[i]=='1' && t[i]=='1'){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
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