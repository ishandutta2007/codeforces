//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
typedef long double ld;
//#define int ll
using namespace std;
mt19937 rnd(time(NULL));
typedef long long ll;
const int N=110;
const int K=155;
const ll inf=1000000000000000001;
string s[N];
void solve(){
    int n,r,b;cin>>n>>r>>b;
    for (int i=0;i<=b;i++) s[i]="";
    for (int i=0;i<r;i++){
        s[i%(b+1)]+="R";
    }
    cout<<s[0];
    for (int i=1;i<=b;i++){
        cout<<"B"<<s[i];
    }
    cout<<endl;





}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}
/**
6 7
1 2 1
2 3 3
3 1 5
4 5 2
5 6 4
6 4 6
3 4 1
1
5 1

**/