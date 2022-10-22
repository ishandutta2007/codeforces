#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int,int>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18, MOD=1e9+7;


int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,m; cin>>n>>m;
    vii l(m); loop(i,0,m) cin>>l[i].x, l[i].y=i;
    if (m>n) return cout<<-1<<endl,0;
    //sort(all(l)); reverse(all(l));
    int sum = 0;
    loop(i,0,m) sum+=l[i].x;
    if (sum<n) return cout<<-1<<endl,0;
    int extra = sum-n;
    int cur = 0;
    vi ans(m);
    loop(i,0,m){
        if (l[i].x>n-i) return cout<<-1<<endl,0;
        ans[l[i].y] = cur;
        cur = cur + 1;
        extra -= (l[i].x -1);
        if (extra<0){
            cur -= extra;
            extra = 0;
        }
    }
    //if (cur!=n) return cout<<-1<<endl,0;
    loop(i,0,m) cout<<ans[i]+1<<" ";
    cout<<endl;

    return 0;
}
/*
color a
cls
g++ a.cpp -o a & a
5 2
4 5

*/