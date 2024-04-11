//#define DEBUG
//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll inf=1000000000000000001ll;
const ll mod=1000000007;
using namespace std;
mt19937 rnd(time(NULL));
int x[3],y[3];
void solve(){
    for (int i=0;i<3;i++) cin>>x[i]>>y[i];
    int res=abs(x[0]-x[1])+abs(y[0]-y[1]);
    if (x[0]==x[1] && x[1]==x[2] && abs(y[0]-y[2])+abs(y[1]-y[2])==abs(y[0]-y[1])) res+=2;
    else if (y[0]==y[1] && y[1]==y[2] && abs(x[0]-x[2])+abs(x[1]-x[2])==abs(x[0]-x[1])) res+=2;
    cout<<res<<endl;

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
1
4 4
1 2
2 3
1 4
4 3
**/