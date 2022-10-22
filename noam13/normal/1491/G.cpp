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
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 4e18, MOD = 1e9+7;

int n;
vii op;
int some = -1;
void solve2(vi& a, vi& b){
    op.pb({b[0], a.back()});
    loop(i,0,a.size()-1) op.pb({b[0], a[i]});
    loop(i,1,b.size()) op.pb({a.back(), b[i]});
    op.pb({b[0], a.back()});
}
void solve1(vi& a){
    int out = some;
    op.pb({out, a.back()});
    loop(i,0,a.size()-1) op.pb({out, a[i]});
    op.pb({out, a.back()});
}
void solveAll(vi& a){
    op.pb({a[0], a.back()});
    op.pb({a[0], a[1]});
    op.pb({a[1], a.back()});
    loop(i,2,a.size()) op.pb({a[i], a[0]});
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin>>n;
    vi a(n);
    loop(i,0,n) cin>>a[i], a[i]--;
    vb check(n);
    vi cyc;
    loop(i,0,n){
        if (check[i]) continue;
        int cur = i;
        vi ind;
        while(!check[cur]){
            check[cur] = 1;
            ind.pb(cur);
            cur = a[cur];
        }
        if (ind.size()==1) {
            some = i;
            continue;
        }
        if (ind.size()==n){
            solveAll(ind);
            break;
        }
        if (cyc.size()) {
            solve2(cyc, ind), cyc.clear();
            some = i;
        }
        else cyc = ind;
    }
    if (cyc.size()) solve1(cyc);
    cout<<op.size()<<endl;
    for(auto p:op) {
        cout<<p.x+1<<" "<<p.y+1<<endl;
        /*swap(a[p.x], a[p.y]);
        a[p.x] = -a[p.x];
        a[p.y] = -a[p.y];*/
    }
    // loop(i,0,n) cout<<a[i]<<" "; cout<<endl;
    return 0;
}
/*
color a
cls
g++ g.cpp -o a & a
6
2 3 4 5 6 1

10
2 3 4 5 1 8 6 7 10 9

3
1 3 2


3
2 1 3



*/