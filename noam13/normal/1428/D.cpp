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


int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    vi a(n); loop(i,0,n) cin>>a[i];
    vi ones;
    int h = 0;
    vii ans;
    vi twos;
    int tri = -1;
    loopr(i,0,n){
        if (a[i]==1) ones.pb(i);
        if (a[i]==2){
            if (!ones.size()) return cout<<-1<<endl,0;
            int j = ones.back(); ones.pop_back();
            ans.pb({i,h});
            ans.pb({j,h++});
            twos.pb(i);
        }
        if (a[i]==3){
            int j = -1;
            if (j==-1 && tri!=-1) j = tri;
            if (j==-1 && twos.size()) j = twos.back(), twos.pop_back();
            if (j==-1 && ones.size()) j = ones.back(), ones.pop_back();
            if (j==-1) return cout<<-1<<endl,0;
            if (a[j]!=1){
                ans.pb({i,h});
                ans.pb({j,h});
                h++;
            }
            else{
                ans.pb({j, h++});
                ans.pb({i, h});
                ans.pb({j, h++});
            }
            tri = i;
        }
    }
    for(int i:ones){
        ans.pb({i, h++});
    }
    cout<<ans.size()<<endl;
    //for(auto p:ans) cout<<(p.x+1)<<" "<<p.y+1<<endl;
    for(auto p:ans) cout<<(n-p.y)<<" "<<p.x+1<<endl;
    return 0;
}
/*
color a
cls
g++ d.cpp -o a & a
6
2 0 3 0 1 1


*/