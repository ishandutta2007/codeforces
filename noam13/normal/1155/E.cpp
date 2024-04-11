#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 2e9, MOD = 1e6+3;
/*
int pp(int b, int p){
    int ans = 1, cur = b;
    while(p){
        if (p&1) ans=ans*cur%MOD;
        p>>=1;
        cur=cur*cur%MOD;
    }
    return ans;
}*/
int pp(int b, int p){
    if (p==0) return 1;
    int v = pp(b*b%MOD, p/2);
    return v * (p%2?b:1) % MOD;
}
int ask(int x){
    cout<<"? "<<x<<endl;
    cin>>x;
    return x;
}
int calc(vi& aa, int x){
    int cur=1, res=0;
    for(auto a:aa) res = (res + cur * a)% MOD,  cur = cur*x%MOD;
    return res;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n = 11;
    vvi mat(n, vi(n+1));
    loop(i,0,n){
        int cur = 1;
        loop(j,0,n) mat[i][j] = cur, cur*=i;
        mat[i][n] = ask(i);
    }
    //loop(i,0,n) { loop(j,0,n+1) cout<<mat[i][j]<<" "; cout<<endl;}
    loop(i,0,n){
        loop(j,i+1,n){
            //do rows i->j 
            int mult = mat[j][i] * pp(mat[i][i],MOD-2) % MOD;
            loop(k,0,n+1) mat[j][k] = (mat[j][k] + MOD - (mult*mat[i][k])%MOD)%MOD;
        }
    }
    loopr(i,0,n){
        loop(j,0,i){
            //do rows i->j 
            int mult = mat[j][i] * pp(mat[i][i],MOD-2) % MOD;
            //cout<<"MULT: "<<mult<<" "<<mat[j][i]<<" "<<pp(2,100)<<endl;
            loop(k,0,n+1) mat[j][k] = (mat[j][k] + MOD - (mult*mat[i][k])%MOD)%MOD;
        }
    }
    //loop(i,0,n) { loop(j,0,n+1) cout<<mat[i][j]<<" "; cout<<endl;}
    vi a(n);
    loop(i,0,n) a[i] = mat[i][n] * pp(mat[i][i], MOD-2) % MOD;
    /*cout<<"A: ";
    loop(i,0,n) cout<<a[i]<<" ";
    cout<<endl;*/
    loop(i,0,MOD) if(calc(a,i)==0) return cout<<"! "<<i<<endl,0;
    cout<<"! "<<-1<<endl;
    return 0;
}
/*
color a
cls
g++ GuessRoot.cpp -o a & a
1000002
0
3
8


7
21
85
247

*/