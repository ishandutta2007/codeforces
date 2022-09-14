//#define DEBUG
//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll inf=2000000000000000001ll;
const int mod=31607;
using namespace std;
mt19937 rnd(time(NULL));
const int N=200010;
int a[N];
bool ans=false;
void F(int pos,int sum,bool was){
    if (pos==0){
        if (was && sum==0){
            ans=true;
        }
        return;
    }
    F(pos-1,sum,was);
    F(pos-1,sum+a[pos],1);
    F(pos-1,sum-a[pos],1);
}
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    ans=false;
    F(n,0,0);
    if (ans) cout<<"YES\n";
    else cout<<"NO\n";
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
//5 10 5 9
/**
10 6
14 6
2 20
9 10
13 18
15 12
11 7
**/