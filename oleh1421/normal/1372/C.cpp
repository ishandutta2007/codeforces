//#pragma GCC optimize("trapv")
///SOLVE ACMP PROBLEM
#include <bits/stdc++.h>
#define y1 y_1
#define endl '\n'
typedef long long ll;
//#define int ll
using namespace std;
const ll mod=1000000007ll;
const int N=500010;
int p[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i];
    int cnt=0;
    int l=-1;
    int r=-1;
    for (int i=1;i<=n;i++){
        if (p[i]!=i){
            cnt++;
            r=i;
            if (l==-1) l=i;
        }
    }
    if (cnt==0){
        cout<<0<<endl;
        return;
    }
    if (r-l+1==cnt){
        cout<<1<<endl;
        return;
    }
    cout<<2<<endl;
}

int32_t main()
{
//    freopen("input.txt","r",stdin);
//    freopen("nothingontv.out","w",stdout);
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
100000 100000

x*x+y*y>=10^10
a*x+b*y<10^10
*/