//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const int N=16000;
const ll mod=998244353;
void solve(){
    int a,b;cin>>a>>b;
    if (a%2==b%2){
        cout<<a/2<<" "<<(b+1)/2<<endl;
    } else cout<<"-1 -1\n";
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