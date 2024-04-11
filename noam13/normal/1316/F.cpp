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
const int INF = 1e18, MOD=1e9+7, MAXN=1e6;

vi inv(MAXN,1);
int mypow(int b, int p){
    if (p==0) return 1;
    int v = mypow(b,p/2);
    return (((v*v)%MOD) * (p%2?b:1))%MOD;
}
vi power;
struct data{
    int pre=0,suf=0,val=0,sz=0;
};

struct SEG{
    int n,sz;
    vector<data> a;
    SEG(int _n){
        n = _n;
        for(sz=1;sz<n;sz<<=1);
        a.resize(2*sz);
    }
    void update(int i, bool to){
        i+=sz;
        if (to){
            a[i].val = 0;
            a[i].pre = a[i].suf = (power[i-sz] * inv[1])%MOD;
            a[i].sz = 1;
        }
        else a[i].val = a[i].pre = a[i].suf = a[i].sz = 0;
        //cout<<"IND"<<ind<<endl;
        for(i>>=1;i;i>>=1){
            a[i].sz = (a[2*i].sz + a[2*i+1].sz)%MOD;
            a[i].pre = (a[2*i].pre + ((a[2*i+1].pre * inv[a[2*i].sz] )%MOD) ) %MOD;
            a[i].suf = (a[2*i+1].suf + ((a[2*i].suf * inv[a[2*i+1].sz] )%MOD) ) %MOD;
            a[i].val = (a[2*i].val + a[2*i+1].val + ((a[2*i].suf * a[2*i+1].pre)%MOD) )%MOD; 
        }
    }
    int val(){
        return a[1].val;
    }
};
int n,q;
int32_t main(){
    ios_base::sync_with_stdio(false);
    inv[1] = mypow(2,MOD-2);
    loop(i,2,MAXN) inv[i] = (inv[i-1] * inv[1])%MOD;
    cin>>n;    
    vii p(n);
    loop(i,0,n){
        cin>>p[i].x;
        p[i].y=i;
    }
    cin>>q; p.resize(n+q);
    vii qur(q);
    loop(i,0,q){
        cin>>qur[i].x>>qur[i].y; qur[i].x--;
        p[i+n].x = qur[i].y;
        p[i+n].y=i+n;
    }
    sort(all(p));
    power.resize(n+q);
    loop(i,0,n+q) power[i]=p[i].x;
    vi conv(n+q);
    loop(i,0,n+q) conv[p[i].y]=i;
    SEG seg(n+q);
    loop(i,0,n) {
        //cout<<"CON: "<<conv[i]<<" "<<power[conv[i]]<<endl;
        seg.update(conv[i],1);
    }
    //cout<<"hi"<<inv[1]<<endl;
    cout<<seg.val()<<endl;
    vi in(n);
    loop(i,0,n) in[i]=i;
    loop(i,0,q){
        seg.update(conv[in[qur[i].x]],0);
        in[qur[i].x] = i+n;
        seg.update(conv[in[qur[i].x]],1);
        cout<<seg.val()<<endl;
    }
    return 0;
}
/*
color a
cls
g++ f.cpp -o a & a
2
1 2
2
1 2
2 1



*/