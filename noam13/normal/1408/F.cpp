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


vii op;
void solve(int l, int r){
    if (l+1==r) return ;
    int mid = (l+r)/2;
    solve(l, mid);
    solve(mid, r);
    int sz = mid-l;
    loop(i,0,sz) op.pb({l+i, mid+i});
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    int base = 0;
    vector<pair<int, vi>> gs;
    loopr(k,0,20){
        if (n & (1<<k)){
            int sz = 1<<k;
            solve(base,base+sz);
            gs.pb({k,vi(0)});
            loop(i,0,sz) gs.back().y.pb(base++);
        }
    }
    while(gs.size()>2){
        int i = gs.size()-1, j = i-1;
        if (gs[i].x==gs[j].x){
            int sz = (1<<gs[i].x);
            loop(k,0,sz) {
                op.pb({gs[i].y[k], gs[j].y[k]});
                gs[j].y.pb(gs[i].y[k]);
            }
            gs.pop_back();
            gs[j].x++;
        }
        else{ //i.x -> i.x+1
            int sz = (1<<gs[i].x);
            loop(k,0,sz){
                int v = gs[0].y.back(); gs[0].y.pop_back();
                op.pb({v, gs[i].y[k]});
                gs[i].y.pb(v);
            }
            gs[i].x++;
        }
    }
    cout<<op.size()<<endl;
    for(auto p:op) cout<<p.x+1<<" "<<p.y+1<<endl;
    return 0;
}
/*
color a
cls
g++ f.cpp -o a & a

*/