#include<bits/stdc++.h>
using namespace std;
template<typename T> ostream& operator<<(ostream& os, vector<T> a){os<<"( ";for(T &x:a)os<<x<<" ";os<<")\n";return os;}
template<typename T> ostream& operator<<(ostream& os, set<T> a){os<<"( ";for(T x:a)os<<x<<" ";os<<")\n";return os;}
template<typename T1, typename T2> ostream& operator<<(ostream& os, pair<T1,T2> a){os<<"("<<a.first<<" "<<a.second<<") ";return os;}
template<typename T> ostream& operator<<(ostream& os, complex<T> a){os<<"(r="<<a.real()<<" i="<<a.imag()<<") ";return os;}
typedef long long ll;
typedef double dd;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;
#define all(a) a.begin(),a.end()
#ifdef OFFLINE
#define DEBUG 1
#else
#define DEBUG 0
#endif
#define debug(a) if(DEBUG)cout<<#a<<" = "<<a<<endl
#define x first
#define y second
const int base=1000000007;
ll power(ll a,ll n,ll mod=base){ll r=1;while(n){if (n&1) r=r*a%mod;a=a*a%mod;n>>=1;}return r;}
//===========================Head=========================//
const dd eps = 1e-9;
const int nmax=100011;

vi e[nmax];
int parent[nmax];

void dfs(int x){
    for (int y:e[x]) if (y!=parent[x]){
        parent[y]=x;
        dfs(y);
    }
}

int main(int argc,char** argv){
    int n;
    scanf("%d",&n);
    vector<dd> P(n+2), sum(n+2);
    dd ans=0;
    for (int i=0;i<n;++i){
        scanf("%lf",&P[i]);P[i] = 1-P[i];
        ans += P[i];
    }
    for (int i=1;i<n;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        e[x].push_back(y);
        e[y].push_back(x);
        ans -= P[x]*P[y];
    }
    parent[0]=n+1;
    dfs(0);
    for(int x=0;x<n;++x){
        sum[parent[x]] += P[x];
    }

    int q;
    scanf("%d",&q);
    while(q--){
        int x;
        dd detal;
        scanf("%d%lf",&x,&detal);detal = 1-detal;
        detal -= P[x];
        ans += detal;
        ans -= detal*(sum[x]+P[parent[x]]);
        P[x] += detal;
        sum[parent[x]] += detal;
        printf("%.9f\n",ans);
    }
}