#include <bits/stdc++.h>
using namespace std;

#define INF 1000000007

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef vector<vector<pair<int,int> > > vvii;

#define all(x) (x).begin(), (x).end()
#define nall(x) (x).rbegin(), (x).rend()
#define tr(x,it) for(auto it = (x).begin();it!=(x).end();++it)
#define ntr(x,it) for(auto it = (x).rbegin();it!=(x).rend();++it)
#define ufy(v) sort(all(v));(v).erase(unique(all((v))),(v).end())
#define sz(a) int((a).size()) 
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back 
#define PB pop_back
#define pf push_front
#define PF pop_front
#define MP make_pair
#define clr clear
#define rz resize
#define C(a,b) memset(a,b,sizeof(a))
#define ia(a,n) FOR(i,0,n-1)cin>>a[i]
#define ia1(a,n) FOR(i,1,n)cin>>a[i]
#define fpresent(c,x) ((c).find(x) != (c).end())  // set,map
#define present(c,x) (find(all(c),x) != (c).end())  //vector
#define F first
#define S second
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define NFOR(i,a,b) for(int i=a;i>=b;--i)
#define rep(i,n) FOR(i,0,n-1)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)
inline int add(int a,int b, int m=INF){a+=b;if(a>=m)a-=m;return a;}
inline int mul(int a,int b, int m=INF){return (int)(((ll)a*(ll)b)%m);}
inline int norm(int x,int m=INF){if(x>=m)x%=m;if(x<0)x+=m;return x;}
inline int neg(int x,int m=INF){x=-x;return norm(x);}
#define mid ((l+r)>>1)
struct node
{
    int col;
    ll sum;
    ll delta;
};
vector<node> t;
void color(int no, int l, int r,int val)
{
    if(t[no].col!=-1)
    {
        t[no].delta+=abs(val-t[no].col);
        t[no].col=val;
        t[no].sum+=t[no].delta*(r-l+1LL);
        if(l!=r)
        {
            t[2*no].delta+=t[no].delta;
            t[2*no].col=t[no].col;
            t[2*no+1].col=t[no].col;
            t[2*no+1].delta+=t[no].delta;
        }
        t[no].delta=0;
        return;
    }
    color(2*no,l,mid,val);
    color(2*no+1,mid+1,r,val);
    t[no].sum=t[2*no].sum+t[2*no+1].sum;
    if(t[2*no].col==t[2*no+1].col)t[no].col=t[2*no].col;
    else t[no].col=-1;
    t[no].col=val;
}

void upd(int no, int l, int r,int ul, int ur, int val)
{
    if(t[no].col!=-1)
    {
        t[no].sum+=t[no].delta*(r-l+1LL);
        if(l!=r)
        {   
            t[2*no].delta+=t[no].delta;
            t[2*no].col=t[no].col;
            t[2*no+1].col=t[no].col;
            t[2*no+1].delta+=t[no].delta;
        }
        t[no].delta=0;
    }
    if(r<ul or l>ur)return;
    if(l>=ul and r<=ur){color(no,l,r,val);return;}
    
    upd(2*no,l,mid,ul,ur,val);
    upd(2*no+1,mid+1,r,ul,ur,val);
    if(t[2*no].col==t[2*no+1].col)t[no].col=t[2*no].col;
    else t[no].col=-1;
    t[no].sum=t[2*no].sum+t[2*no+1].sum;
    
}
ll qry(int no, int l, int r, int ql, int qr)
{
    if(t[no].col!=-1)
    {
        t[no].sum+=t[no].delta*(r-l+1LL);
        if(l!=r)
        {
            t[2*no].delta+=t[no].delta;
            t[2*no].col=t[no].col;
            t[2*no+1].col=t[no].col;
            t[2*no+1].delta+=t[no].delta;
        }
        t[no].delta=0;
    }
    if(r<ql or l>qr)return 0;
    if(l>=ql and r<=qr)return t[no].sum;
    return qry(2*no,l,mid,ql,qr)+qry(2*no+1,mid+1,r,ql,qr);
}
void build(int no, int l, int r)
{
    if(l==r){t[no].col=r;return;}
    build(2*no,l,mid);
    build(2*no+1,mid+1,r);
    t[no].col=-1;
}


int main()
{
    boost;
    int n,m;
    cin>>n>>m;
    t.rz(5*n);
    build(1,1,n);
    //print(1,1,n);
    while(m--)
    {
        int tp;cin>>tp;
        if(tp==1)
        {
            int l,r,x;
            cin>>l>>r>>x;
            upd(1,1,n,l,r,x);
            // cout<<"UPD: "<<l<<" "<<r<<" "<<x<<"\n";
            // print(1,1,n);
            // cout<<"DONE\n";
        }
        else
        {
            int l,r;cin>>l>>r;
            cout<<qry(1,1,n,l,r)<<"\n";
        }
    }
    return 0;
}