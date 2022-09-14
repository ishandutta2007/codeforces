//#define DEBUG
//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
mt19937 rnd(time(NULL));
const int Q=30000;
const int inf=1000000001;
const int N=50010;
int used[N];


void solve(){
    ll a,b;cin>>a>>b;
    if (a==b){
        cout<<"0 0\n";
        return;
    }
    if (a>b) swap(a,b);
    ll d=b-a;
    ll res=a;
    res=min(res,a%d);
    res=min(res,d-a%d);
    res=min(res,d-b%d);
    res=min(res,b%d);
    cout<<d<<" "<<res<<endl;
}
int main()
{
//    freopen("events.in","r",stdin);
//    freopen("events.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}

/**
6 8
1 4
1 5
2 4
2 5
2 3
2 6
1 7
2 7
**/
//4 4
//1 2
//2 4
//1 4
//2 3
// 2 2 2 2 3 4 3 5
//
// 00000
// 01000
// 00011
// 00000
// 00000

//4 3
//4 9
//4 9
//4 9
//1 2
//
//? 2 3 4
//? 1 3 4
//? 1 2 4
//? 1 2 3