#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const int N=1000010;
int a[N];
void solve(){
    int n,m;cin>>n>>m;
    string s;cin>>s;
    int xL,xR,yL,yR,x,y;
    xL=xR=yL=yR=x=y=0;
    int r=1,c=1;
    for (int i=0;i<s.size();i++){
        if (s[i]=='L') y--;
        else if (s[i]=='R') y++;
        else if (s[i]=='D') x++;
        else x--;
        xL=min(xL,x);
        xR=max(xR,x);
        yL=min(yL,y);
        yR=max(yR,y);
        if (xR-xL+1>n || yR-yL+1>m) break;
        r=1-xL;
        c=1-yL;
    }
    cout<<r<<" "<<c<<endl;


}
int32_t  main()
{
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
4
1 2 5 2
BRBR
**/