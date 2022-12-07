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
#define X first
#define R second.first
#define P second.second
const int base=1000000007;
ll power(ll a,ll n,ll mod=base){ll r=1;while(n){if (n&1) r=r*a%mod;a=a*a%mod;n>>=1;}return r;}
//===========================Head=========================//
const int nmax=100011;
int n, trie[nmax*200][3], ntrie;

void push(int k,int key,int val){
    for (int i=30;i--;){
        int t=(key>>i)&1;
        if (trie[k][t]==0) trie[k][t]=++ntrie;
        k=trie[k][t];
        trie[k][2]+=val;
    }
}

int query(int k,int key){
    int ans=0;
    for (int i=30;i--;){
        int t=(key>>i)&1;
        if (t==1) ans += trie[trie[k][0]][2];
        if (trie[k][t]==0) break;
        k=trie[k][t];
    }
    return ans;
}

void update(int i,int p,int val){
    for (++i;i<=n;i+=i&-i) push(i,p,val);
}

int show(int i,int L,int H){
    H = min(1000000000,H);
    L = max(L,0);
    int ans=0;
    for (++i;i;i-=i&-i) ans+=query(i,H+1)-query(i,L);
    return ans;
}

int main(int argc,char** argv){
    int k;
    scanf("%d%d",&n,&k);
    vector<pair<int,pii>> a(n);
    for (auto &A:a) scanf("%d%d%d",&A.X,&A.R,&A.P);
    sort(all(a));

    ntrie = n;
    priority_queue<pii,vii,greater<pii>> heap;
    ll ans=0;
    for (int i=0;i<n;++i){
        while(heap.size()){
            auto tmp = heap.top();
            debug(tmp);
            if (tmp.first >= a[i].X) break;
            int j=tmp.second;
            update(j,a[j].P,-1);
            heap.pop();
        }
        pair<int,pii> tmp = make_pair(a[i].X-a[i].R,make_pair(-1,-1));
        int j=upper_bound(all(a),tmp)-a.begin();
        debug(tmp);
        debug(j);
        ans += show(i,a[i].P-k,a[i].P+k)-show(j-1,a[i].P-k,a[i].P+k);
        update(i,a[i].P,1);
        heap.push({a[i].X+a[i].R,i});
    }
    cout<<ans;
}