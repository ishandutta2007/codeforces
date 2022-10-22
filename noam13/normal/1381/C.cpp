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
    int n,x,y; cin>>n>>x>>y;
    vi arr(n);
    vvi ind(n+1);
    loop(i,0,n){
        int a; cin>>a; a--;
        arr[i]=a;
        ind[a].pb(i);
    }
    vvi put(n+1);
    int miss = -1;
    set<ii> s; 
    loop(i,0,n+1) {
        if (ind[i].size()) s.insert({-ind[i].size(),i});
        else miss = i;
    }
    int amt = x;
    loop(_,0,amt){
        ii p = *s.begin();
        s.erase(s.begin()); 
        p.x++; put[p.y].pb(p.y);
        if (p.x!=0) s.insert(p);
    }
    vi ans(n);
    loop(i,0,n+1){
        int r = put[i].size();
        for(auto p:put[i]) {
            //cout<<"HI "<<ind[i].back()<<" "<<p<<endl;
            ans[ind[i].back()]=p;
            ind[i].pop_back();
        }
    }
    //if (s.size() && -2*(s.begin()->x) > n-x) return cout<<"NO"<<endl,0;
    amt = n-y;
    vi aa, col;
    loop(i,0,n+1) for(auto in:ind[i]) {
        //cout<<"SIZE "<<aa.size()<<endl;
        col.pb(i);
        aa.pb(in);
    }
    /*cout<<"A: "; for(auto x:aa) cout<<x<<" "; cout<<endl;
    cout<<"COL: "; for(auto x:col) cout<<x<<" "; cout<<endl;*/
    int r = aa.size();
    int offset = (r)/2;
    loop(i,0,r) {
        ans[aa[i]] = col[(i+offset) % r];
        //cout<<aa[i]<<" "<<col[i]<<" "<<ans[aa[i]]<<endl;
        if (ans[aa[i]]==col[i]){
            if (amt==0) return cout<<"NO"<<endl,0;
            ans[aa[i]] = miss;
            amt--;
        }
    }
    loop(i,0,n) if(ans[i]!=miss && ans[i]!=arr[i] && amt) ans[i]=miss, amt--;
    //cout<<"AMT "<<amt<<endl;
    cout<<"YES"<<endl;
    loop(i,0,n) cout<<ans[i]+1<<" ";
    cout<<endl;
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
g++ c.cpp -o a & a
7
5 2 4
3 1 1 2 5
5 3 4
1 1 2 1 2
4 0 4
5 5 3 3
4 1 4
2 3 2 3
6 1 2
3 2 1 1 1 1
6 2 4
3 3 2 1 1 1
6 2 6
1 1 3 2 1 1

*/