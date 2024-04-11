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
const int N=400010;
void solve(){
    int n,a,b;cin>>n>>a>>b;

    string s;cin>>s;
    int res=(int)s.size()*a;
    if (b<0){
        int cnt=0;
        for (int i=1;i<s.size();i++) cnt+=(s[i]!=s[i-1]);
        res+=((cnt+3)/2)*b;
    } else {
        res+=(int)s.size()*b;
    }
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