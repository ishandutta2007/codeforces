#include <bits/stdc++.h>
#include <ext/hash_map>
#include <ext/hash_set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define XINF INT_MAX
#define INF 0x3F3F3F3F
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define RIT reverse_iterator
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update > rb_tree_set;
typedef tree<int, int, greater<int>, rb_tree_tag, tree_order_statistics_node_update > rb_tree;
#define PQ std::priority_queue
#define HEAP __gnu_pbds::priority_queue
#define X first
#define Y second
#define lson(X) ((X)<<1)
#define rson(X) ((X)<<1|1)

ll a[100000];
int n,m;

ll S(int l, ll x) {
    ll s=0;
    REP(i,l) {
        s+=abs(x+i);
    }
    return s;
}

int gao(int l, int r, ll L, ll R) {
    int len = (r-l)/m+1;
    R-=len-1;
    if(L>R) return 1;
    if(l>r) return 0;
    int ans = 0;
    
    ll mx = LLONG_MAX;
    ll sl = S(len,L), sr = S(len,R);
    if(sl<mx) {
        mx=sl;
        ans=L;
    }
    if(sr<mx) {
        mx=sr;
        ans=R;
    }
    if(L<=-len/2 && R>=-len/2) ans = -len/2;
    /*
    while(L<=R) {
        ll A=(2*L+R)/3;
        ll B=(L+2*R)/3;
        ll sa = S(len,A), sb = S(len,B);
        if(sa<mx) {
            mx=sa;
            ans=A;
        }
        if(sb<mx) {
            mx=sb;
            ans=B;
        }
        if(sa<sb) {
            R=B-1;
        }else{
            L=A+1;
        }
    }*/ 
    int k=0;
    for(int i=l;i<=r;i+=m) a[i]=ans+(k++);
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    string s;
    REP(i,n) {
        cin>>s;
        if(s=="?") {
            a[i]=INF;
        }else{
            a[i]=atoi(s.c_str());
        }
    }
    set<int> mp;
    int f=0;
    REP(i,m) {
        VI v;
        int c=0;
        for(int j=i;j<n;j+=m) {
            if(a[j]!=INF) v.PB(j);
            c++;
        }
        if(v.size()==0) {
            int k=0;
            for(int j=i;j<n;j+=m) {
                a[j]=-c/2+k++;
            }
        }else{
            f|=gao(i,v[0]-m,-INF,a[v[0]]-1);
            REP(j,(int)v.size()-1) {
                f|=gao(v[j]+m,v[j+1]-m,a[v[j]]+1,a[v[j+1]]-1);
            }
            f|=gao(v[(int)v.size()-1]+m,i+(c-1)*m,a[v[(int)v.size()-1]]+1,INF);
        }
    }
    if(f) {
        cout<<"Incorrect sequence"<<endl;
        return 0;
    }
    REP(i,n) {
        cout<<a[i]<<' ';
    }
    return 0;
}