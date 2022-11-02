//George1123
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef vector<int> vi;
typedef pair<int,int> pii;

#define x first
#define y second
#define sz(a) (int)((a).size())
#define all(a) (a).begin(),(a).end()
#define R(i,n) for(int i=0;i<(n);++i)
#define L(i,n) for(int i=(n)-1;i>=0;--i)

constexpr int inf32=0x3f3f3f3f;
constexpr i64 inf64=0x3f3f3f3f3f3f3f3f;

typedef pair<i64,i64> funt;
funt operator+(funt a,funt b)
    {return funt(a.x+b.x,a.y+b.y);}
funt operator-(funt a,funt b)
    {return funt(a.x-b.x,a.y-b.y);}

vi ls(1),rs(1);
vector<funt> key(1);
int newn(){
    // if(sz(ls)>=30)cout<<sz(ls)<<endl;
    ls.push_back(0);
    // if(sz(ls)>=30)cout<<sz(rs)<<endl;
    rs.push_back(0);
    // if(sz(ls)>=30)cout<<sz(key)<<endl;
    key.push_back(funt(0,0));
    // if(sz(ls)>=30)cout<<"newok"<<endl;
    return sz(key)-1;
} //vector  RE

// constexpr int L=1e7;
// int ls[L],rs[L],top=1;
// funt key[L];
// int newn(){return top++;} //  AC

#define mid (l+r>>1)

int add(int u,int i,funt k,int l,int r){
    // if(i==2)cout<<u<<" "<<ls[u]<<" "<<rs[u]<<" "<<i<<" "<<l<<" "<<r<<endl;
    if(r<=i||i<l) return u;
    // if(i==2)cout<<sz(key)<<endl;
    int v=newn();//if(i==2)cout<<v<<endl;
    key[v]=key[u]+k;
    if(r-l==1) return v;
    int x,y;
    x=add(ls[u],i,k,l,mid);
    y=add(rs[u],i,k,mid,r);
    ls[v]=x;rs[v]=y;
    // cout<<"*"<<v<<" "<<ls[v]<<" "<<rs[v]<<" "<<u<<" "<<i<<" "<<l<<" "<<r<<endl;
    return v;
}

void print(int u,int l,int r){
    if(!u) return;
    cout<<"u="<<u<<":["<<l<<","<<r<<"]\n";
    print(ls[u],l,mid),print(rs[u],mid,r);
}

funt get(int u,int v,int i,int l,int r){
    if(i<=l) return funt(0,0);
    if(r<=i) return key[v]-key[u];
    return get(ls[u],ls[v],i,l,mid)
        +get(rs[u],rs[v],i,mid,r);
}

constexpr int W=1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    int n;
    cin>>n;
    vector<int> p(n+1);
    int rt=0;
    R(t,n){
        int l,r,x[3],y;
        cin>>l>>r>>x[0]>>y>>x[1]>>x[2],++l,++r;
        rt=add(rt,0,funt(x[0],0),0,W);
        rt=add(rt,l,funt(x[1]-x[0],y),0,W);
        rt=add(rt,r,funt(x[2]-x[1],-y),0,W);
        p[t+1]=rt;
    }
    
    int nq;
    cin>>nq;
    i64 ns=0;
    while(nq--){
        int l,r,i;
        cin>>l>>r>>i,--l;
        i=(ns+i)%W;
        funt f=get(p[l],p[r],i+1,0,W);
        // cout<<p[l]<<" "<<p[r]<<" "<<f.x<<' '<<f.y<<' '<<i<<endl;
        // cout<<"res="<<f.x+f.y*i<<endl;
        cout<<(ns=f.x+f.y*i)<<'\n';
    }

    return 0;
}