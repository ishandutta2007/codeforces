#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#define endl '\n'
using namespace __gnu_pbds;
typedef long double ld;
//#define int ll
using namespace std;
mt19937 rnd(time(NULL));
typedef long long ll;
const ll mod=998244353;
const ll inf=1000000000000000001;
const int N=300010;
int ask(int w){
    cout<<"? "<<w<<endl;
    int h;cin>>h;
    return h;
}
void solve(){
    int n;cin>>n;
    int S=0;
    for (int i=27;i>=0;i--){
        if (ask(S+(1<<i))!=1) S+=(1<<i);
    }
    S++;
    int res=S;
    S-=n-1;
    for (int i=1;i<=n;i++){
        int w=(S+n-1)/i;
        int h=ask(w);
        if (h) res=min(res,w*h);
    }
    cout<<"! "<<res<<endl;


}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }

    return 0;
}

/**
1
5
1 2 4 2 1
4 2 2 1 1
  ,        .
**/