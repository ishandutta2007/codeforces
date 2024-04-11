#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvvvi vector<vvvi>
#define vvvvvi vector<vvvvi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18, MOD = 1e9+7;


int solve(){
    int n,s,e; cin>>n>>s>>e; s--; e--;
    int l = e-s+1;
    vi sz(n);
    loop(i,0,n-1) sz[i] = 2 * (n-1-i);
    sz[n-1]=1;
    int sseg = -1;
    int sum = 0;
    //cout<<"SZ: ";loop(i,0,n) cout<<sz[i]<<" "; cout<<endl;
    loop(i,0,n){
        sum+=sz[i];
        s-=sz[i];
        sseg = i;
        if (s<0){
            //cout<<"BI: "<<endl;
            s+=sz[i];
            break;
        }
    }
    //cout<<"S: "<<sseg<<" "<<s<<", "<<sum<<endl;
    vi ans;
    while(1){
        if (sseg==n-1) break;
        int m = sz[sseg];
        //cout<<"M: "<<m<<endl;
        vi curseg(m);
        loop(i,0,m/2){
            curseg[i*2] = sseg;
            curseg[i*2+1] = sseg + i + 1;
        }
        loop(i,s,m){
            if (ans.size()==l) break;
            ans.pb(curseg[i]);
        }
        if (ans.size()==l) break;
        //cout<<"SIZE: "<<ans.size()<<endl;
        s=0; sseg++;
    }
    if (ans.size()<l){
        ans.pb(0);
    }
    for(auto x:ans) cout<<x+1<<" "; cout<<endl;
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
g++ d.cpp -o a & a
3
2 1 3
3 3 6
99995 9998900031 9998900031

*/