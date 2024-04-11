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
const int INF = 4e18, MOD = 1e9+7;


int32_t main(){
    ios_base::sync_with_stdio(false);
    string s; cin>>s;
    int x,y; cin>>x>>y;
    if (x>y){
        swap(x,y);
        for(char &c:s) {
            if (c=='0') c = '1';
            else if (c=='1') c = '0';
        }
    }
    int n = s.size();
    vi z(n+1), o(n+1), m(n+1);
    vi pref(n+1);
    loop(i,0,n){
        z[i+1] = z[i] + (s[i]=='0');
        o[i+1] = o[i] + (s[i]=='1');
        m[i+1] = m[i] + (s[i]=='?');
        pref[i+1] = pref[i];
        if (s[i]=='1'){
            pref[i+1]+=(z[i]+m[i])*x;
        }
        else pref[i+1]+=y*o[i];
    }
    reverse(all(s));
    vi sz(n+1), so(n+1), sm(n+1);
    vi suf(n+1);
    loop(i,0,n){
        sz[i+1] = sz[i] + (s[i]=='0');
        so[i+1] = so[i] + (s[i]=='1');
        sm[i+1] = sm[i] + (s[i]=='?');
        suf[i+1] = suf[i];
        if (s[i]=='0'){
            suf[i+1]+=x*(so[i]+sm[i]);
        }
        else suf[i+1]+=sz[i]*y; 
    }
    reverse(all(sz)), reverse(all(so)), reverse(all(sm)), reverse(all(suf));
    int ans = INF;
    loop(i,0,n+1){
        //cout<<"HI: "<<endl;
        //cout<<pref[i]<<" "<<suf[i]<<" "<<(x * (z[i]+m[i])*(so[i]+sm[i]) + y * o[i] * sz[i])<<endl;
        chkmin(ans, pref[i] + suf[i] + x * (z[i]+m[i])*(so[i]+sm[i]) + y * o[i] * sz[i]);
    }
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ b.cpp -o a & a
?10?
239 7

?????
13 37

*/