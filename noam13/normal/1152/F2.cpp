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
const int INF = 1e18, MOD=1e9+7;

int n,k,m;
int conv(int j, int mask){
    return mask + j * (1<<m);
}
void add(int& a, int b){
    a = (a+b)%MOD;
}
vvi operator*(const vvi& a,const vvi& b){
    vvi mat(a.size(),vi(b[0].size(),0));
    loop(i,0,a.size()){
        loop(j,0,b[0].size()){
            loop(k,0,b.size()){
                add(mat[i][j], a[i][k] * b[k][j]);
            }
        }
    }
    return mat;
}
vvi identity(int n){
    vvi mat(n,vi(n,0));
    loop(i,0,n) mat[i][i] = 1;
    return mat;
}
vvi power(const vvi& b, int p){
    if (p==0) return identity(b.size());
    vvi mat = power(b,p/2);
    mat = mat * mat;
    if (p&1) mat = mat * b;
    return mat;
}
void print(vvi& a){
    loop(i,0,a.size()) {loop(j,0,a[i].size()) cout<<a[i][j]<<" "; cout<<endl;}
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin>>n>>k>>m;
    vvi mat((k+1)*(1<<m),vi((k+1)*(1<<m)));
    loop(j,0,k+1){
        loop(mask,0,1<<m){
            int next = (mask<<1)&((1<<m) -1);
            add(mat[conv(j,mask)][conv(j,next)],1);
            if(j<k) add(mat[conv(j,mask)][conv(j+1,next|1)],__builtin_popcount(mask)+1);
        }
    }
    //print(mat);
    mat = power(mat,n);
    //mat = vvi(mat.size(),vi(mat[0].size(),1)) * mat;
    //print(mat);
    vvi base(mat.size(),vi(mat.size(),0)); base[0][0]=1;
    //print(base);
    mat = base * mat;
    //print(mat);
    int ans=0;
    loop(mask,0,1<<m) add(ans, mat[0][conv(k,mask)]);
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ NekoCatniverse.cpp -o a & a
3 3 1




*/