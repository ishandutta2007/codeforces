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


const int MAXN = 8e6;
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    /*vvi g(n);
    loop(x,1,n){
        int a = 2*x;
        int b = a^x;
        int c = a+x;
        int d = b+x;
        int e = c^d;
        vi vec = {e};
        b = a = x;
        while(b) a*=2, b/=2;
        a/=2;
        c = a^x;
        d = a+x;
        e = c+x;
        vec.pb(d^e);
        if (x==2049) cout<<"C^D "<<vec.back()<<endl;
        for(auto y:vec) if(y<n) g[y].pb(x);
    }*/
    bitset<MAXN> check, op;
    vi from(8*n);
    queue<int> q; 
    q.push(n); check[n] = 1;
    bool fin = 0;
    while(q.size()){
        int x = q.front(); q.pop();
        int a = 2*x;
        int b = a^x;
        int c = a+x;
        int d = b+x;
        int e = c^d;
        vii vec = {{e,0}};
        b = a = x;
        while(b>1) a*=2, b/=2;
        c = a^x;
        d = a+x;
        e = c+x;
        vec.pb({d^e,1});
        for(auto p:vec){
            if (p.x>=8*n) continue;
            if (!check[p.x]){
                q.push(p.x);
                check[p.x] = 1;
                op[p.x] = p.y;
                from[p.x] = x;
            }
            if (p.x==1) fin = 1;
        }
        if (fin) break;
    }
    int cur = 1;
    vi nums; vi ops;
    while(cur!=n){
        ops.pb(op[cur]);
        cur = from[cur];
        nums.pb(cur);
        //cout<<"CUR: "<<ops.back()<<" "<<nums.back()<<endl;
    }
    reverse(all(nums));
    reverse(all(ops));
    vector<string> res;
    int r = nums.size();
    loop(i,0,r){
        int x = nums[i];
        //cout<<"X: "<<x<<" "<<ops[i]<<endl;
        if (ops[i]){
            int b = x, a = x;
            while(b>1) {
                res.pb(to_string(a) + " + " + to_string(a));
                a*=2, b/=2;
            }
            int c = a^x, d = a+x, e = c+x;
            res.pb(to_string(a) + " ^ " + to_string(x));
            res.pb(to_string(a) + " + " + to_string(x));
            res.pb(to_string(c) + " + " + to_string(x));
            res.pb(to_string(d) + " ^ " + to_string(e));
        }
        else{
            int a = 2*x;
            int b = a^x;
            int c = a+x;
            int d = b+x;
            int e = c^d;
            res.pb(to_string(x) + " + " + to_string(x));
            res.pb(to_string(a) + " ^ " + to_string(x));
            res.pb(to_string(a) + " + " + to_string(x));
            res.pb(to_string(b) + " + " + to_string(x));
            res.pb(to_string(c) + " ^ " + to_string(d));
            //cout<<"F: "<<x<<" "<<(e)<<endl;
        }
    }
    cout<<res.size()<<endl;
    for(auto s:res) cout<<s<<endl;
    return 0;
}
/*
color a
cls
g++ e.cpp -o a & a
999999

*/