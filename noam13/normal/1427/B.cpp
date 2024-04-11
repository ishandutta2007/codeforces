#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 4e18;

int solve(){
    int n,k; cin>>n>>k;
    string s; cin>>s;
    int res = 0, cnt=0;
    loop(i,0,n) if(s[i]=='W') res++;
    if (res==0){
        if (k==0) return cout<<0<<endl,0;
        return cout<<2*k-1<<endl,0;
    }
    bool f = 1; int cntf = 0;
    vi l;
    loop(i,0,n){
        cnt = 0;
        while(i<n && s[i]=='L') cnt++, i++;
        if (i==n) break;
        if (f) cntf = cnt;
        else l.pb(cnt);
        cnt = f = 0;
    }
    sort(all(l));
    for(auto x:l){
        if (x<=k) k-=x, res+=2*x+1;
        else{
            res += 2*k;
            k = 0;
            break;
        }
    }
    int amt = min(k, cnt);
    res+=amt*2; 
    k-=amt;
    amt = min(k, cntf);
    res+=2*amt;
    cout<<res<<endl;
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    loop(i,0,t) solve();
    return 0;
}
/*
color a
cls
g++ b.cpp -o a & a
8
5 2
WLWLL
6 5
LLLWWL
7 1
LWLWLWL
15 5
WWWLLLWWWLLLWWW
40 7
LLWLWLWWWLWLLWLWWWLWLLWLLWLLLLWLLWWWLWWL
1 0
L
1 1
L
6 1
WLLWLW


*/