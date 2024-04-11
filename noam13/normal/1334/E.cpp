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
const int INF = 1e18, MOD = 998244353, MAXF = 100;


int pp(int b, int p){
    if (p==0) return 1;
    int v = pp(b, p/2);
    return ((v*v)%MOD)*(p%2?b:1)%MOD;
}
int gcd(int a, int b){
    if (a>b) swap(a,b);
    if (a==0) return b;
    return gcd(b%a,a);
}
vi fact(MAXF,1), antifact(MAXF,1);
vii divs;
map<int, int> ans;
void dfs(int i, int num=1, int sum=0, int anti=1){
    if (i==0){
        ans[num] = (fact[sum] * anti)%MOD;
        return ;
    }
    i--;
    loop(amt,0,divs[i].y+1){
        dfs(i,num, sum+amt, (anti * antifact[amt])%MOD);
        num*=divs[i].x;
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    loop(i,1,MAXF) fact[i]=(fact[i-1]*i)%MOD;
    loop(i,0,MAXF) antifact[i]=pp(fact[i], MOD-2);
    int d; cin>>d;
    for(int i=2;i*i<=d;i++){
        int cnt = 0;
        while(d%i==0) d/=i, cnt++;
        if (cnt) divs.pb({i,cnt});
    }
    if (d>1) divs.pb({d,1});
    //for(auto p:divs) cout<<"DIVS: "<<p.x<<" "<<p.y<<endl;
    dfs(divs.size());
    int q; cin>>q;
    loop(i,0,q){
        int a,b; cin>>a>>b;
        int g = gcd(a,b);
        int res = ans[a/g]*ans[b/g]%MOD;
        cout<<res<<endl;
    }
    return 0;
}
/*
color a
cls
g++ e.cpp -o a & a
12
3
4 4
12 1
3 4

288807105787200
4
46 482955026400
12556830686400 897
414 12556830686400
4443186242880 325
*/