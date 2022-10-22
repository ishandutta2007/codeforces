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
const int INF = 1e18, MAXN = 2e5+20, MOD=998244353;

int mpow(int b, int p){
    if (p==0) return 1;
    int v=  mpow(b,p/2);
    return ((v*v)%MOD * (p%2?b:1))%MOD;
}
vi fact(MAXN,1);
int choose(int a, int b){
    int v = (fact[a] * mpow(fact[b],MOD-2))%MOD;
    return (v * mpow(fact[a-b],MOD-2))%MOD;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,m; cin>>n>>m;
    
    loop(i,1,MAXN) fact[i] = (fact[i-1] * i)%MOD;
    int ans = choose(m,n-1);
    ans = (ans * (n-2))%MOD;
    ans = (ans*mpow(2,n-3))%MOD;
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ d.cpp -o a & a
3 4


*/