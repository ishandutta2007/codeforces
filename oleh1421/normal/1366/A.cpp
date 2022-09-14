//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
typedef long double ld;
//#define double ld
using namespace std;
const int N=5000001;
void solve(){
    int a,b;cin>>a>>b;
    if (a>b) swap(a,b);
    if (a+a<=b){
        cout<<a<<endl;
        return;
    }
    int res=0;
    int X=(a+a-b)/3;
    for (int x=X-100;x<=X+100 && x+x<=a && x<=b;x++){
        res=max(res,x+min(a-x-x,(b-x)/2));
    }
    cout<<res<<endl;
}
int main()
{
//    freopen("fuel.in","r",stdin);
//    freopen("fuel.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/*
3 4
1 3
5
9 2 7 7
6 1 0 9
4 7 4 6
*/