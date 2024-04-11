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
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 2e18, MOD = 1e9+7;

map<ii, int> cache;

int ask(int a, int b){
    if (a>b) swap(a,b);
    if (cache[ii(a,b)]) return cache[ii(a,b)];
    cout<<"? "<<a+1<<" "<<b+1<<endl;
    int v; cin>>v;
    return cache[ii(a,b)]=v;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    int mask = 1, log = 0;
    while(mask<n) mask*=2, log++;
    mask--;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    vi cand(n); loop(i,0,n) cand[i] = i;
    while(cand.size()>2){
        int m = cand.size();
        auto dist = uniform_int_distribution<int>(0, m-1);
        int a=-1,b=-1;
        while(1){
            a = dist(rng), b = a;
            while(b==a) b = dist(rng);
            int cnt = __builtin_popcount(ask(cand[a],cand[b]));
            if ((1<<(2*cnt))-1<=m) break;
        }
        vi nc, res(m,INF);
        loop(i,0,m){
            if (i!=a){
                res[i] = ask(cand[i], cand[a]);
                chkmin(res[a],res[i]);
            }
        }
        loop(i,0,m) if(res[i]==res[a]) nc.pb(cand[i]);
        a = -1;
        cand = nc;
    }
    auto dist = uniform_int_distribution<int>(0, n-1);
    int z = cand[0];
    if (cand.size()>1){
        int b = cand[1];
        while(1){
            int c = b;
            while(c==b || c==z) c = dist(rng);
            int v1 = ask(z,c), v2 = ask(b,c);
            if (v1!=v2){
                if (v1>v2) z = b;
                break;
            }
        }
    }
    vi per(n,0);
    loop(i,0,n) if(i!=z) per[i]=ask(z,i);
    cout<<"! ";
    loop(i,0,n) cout<<per[i]<<" ";
    cout<<endl;
    return 0;
}
/*
color a
cls
g++ X-OR.cpp -o a & a




 
 
 
 
 
*/