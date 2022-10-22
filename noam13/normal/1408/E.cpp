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

struct DSU{
    int n;
    vi p,sz;
    DSU(int n): n(n), p(n,-1), sz(n,1){}
    int find(int c){
        //cout<<"C: "<<c<<endl;
        if (p[c] == -1) return c;
        return p[c] = find(p[c]);
    }
    bool uni(int a, int b){
        //cout<<"KKI: "<<a<<" "<<b<<endl;
        a = find(a), b = find(b);
        if (a==b) return 0;
        if (sz[a]>sz[b]) swap(a,b);
        p[a] = b;
        sz[b] += sz[a];
        return 1;
    }
};
int solve(){
    int m,n; cin>>m>>n;
    vi a(m), b(n);
    int sa=0, sb=0;
    loop(i,0,m) {
        cin>>a[i];
        sa+=a[i];
    }
    loop(i,0,n) {
        cin>>b[i];
        sb+=b[i];
    }
    /*sort(all(a)); sort(all(b));
    vi pera(m), perb(n);
    loop(i,0,m) pera[a[i].y] = i;
    loop(i,0,n) perb[b[i].y] = i;*/
    vvi sets(m);
    vi ss(m);
    int ans = 0;
    loop(i,0,m){
        int s; cin>>s;
        sets[i].resize(s);
        ss[i] = s;
        ans += s * a[i];
        loop(j,0,s) cin>>sets[i][j], sets[i][j]--, ans+=b[sets[i][j]];
        sort(all(sets[i]), [&](int x, int y){
            return b[x]>b[y];
        });
        //for(auto x:sets[i]) cout<<x<<" "; cout<<endl;
    }
    DSU dsu(m+n);
    set<pair<int, ii>> bests;
    loop(i,0,m) {
        int j = sets[i][0];
        bests.insert({-(a[i]+b[j]), {i,0}});
    }
    while(bests.size()){
        auto tmp = *bests.begin(); bests.erase(bests.begin());
        int v = tmp.x, i =tmp.y.x, jj = tmp.y.y, j = sets[i][jj];
        if (dsu.uni(i, m+j)){
            ans += v;
        }
        if ((++jj) < ss[i]){
            //cout<<"HI: "<<endl;
            bests.insert({-(a[i] + b[sets[i][jj]]), {i,jj}});
            //cout<<"BI: "<<endl;
        }
    }
    cout<<ans<<endl;
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
/*
color a
cls
g++ e.cpp -o a & a
3 2
1 2 3
4 5
2 1 2
2 1 2
2 1 2

*/