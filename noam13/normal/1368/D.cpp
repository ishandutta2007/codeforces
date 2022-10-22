#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;--i)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 4e18, MOD = 1e9+7;
const double eps = 1e-9;


int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    int log = 20;
    vi cnt(log);
    loop(i,0,n){
        int a; cin>>a;
        loop(j,0,log){
            cnt[j]+=(a&1);
            a>>=1;
        }
    }
    int ans = 0;
    while(cnt.size()){
        int mini =INF;
        int cur = 0, mult=1;
        for(auto x:cnt){
            if (x){
                chkmin(mini,x);
                cur+=mult;
            }
            mult<<=1;
        }
        for(auto &x:cnt) if(x) x-=mini;
        ans+= mini * cur * cur;
        while(cnt.size() && cnt.back()==0) cnt.pop_back();
    }
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ d.cpp -o a & a
1
123

*/