#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

using namespace std;
using namespace __gnu_pbds;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const gp_hash_table<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

const int N=1e5+5,mod=1e9+7;
int add(int a,int b){
    a+=b;
    if(a>=mod)
        a-=mod;
    return a;
}
int sub(int a,int b){
    a-=b;
    if(a<0)
        a+=mod;
    return a;
}
int mul(int a,int b){return (ll)a*b%mod;}
int pwrmod(int x,int k){
    int ans=1;
    for(;k;k>>=1,x=mul(x,x))
        if(k&1)
            ans=mul(ans,x);
    return ans;
}
/*struct segTree{
    vector<int> sum,lazy;
    vector<bool> reset;
    segTree(){sum.resize(4*N);lazy.resize(4*N);reset.resize(4*N);}
    void prop(int i){
        if(reset[i]){
            sum[2*i]=sum[2*i+1]=lazy[2*i]=lazy[2*i+1]=0;
            reset[2*i]=reset[2*i+1]=1;
            reset[i]=0;
        }
        if(lazy[i]){
            lazy[2*i]=add(lazy[2*i],lazy[i]);
            lazy[2*i+1]=add(lazy[2*i+1],lazy[i]);
            lazy[i]=0;
        }
    }
    void resetuj(){reset[1]=1;sum[1]=lazy[1]=0;}
    void sett(int qs,int qe,int x,int l=0,int r=N-1,int i=1){
        if(qs>r||qe<l)
            return;
        if(qs<=l&&qe>=r){
            lazy[i]=add(lazy[i],x);
            return;
        }
        int m=(l+r)>>1;
        prop(i);
        sett(qs,qe,x,l,m,2*i);
        sett(qs,qe,x,m+1,r,2*i+1);
        sum[i]=add(sum[2*i],sum[2*i+1]);
        if(lazy[2*i])
            sum[i]=add(sum[i],mul(lazy[2*i],m-l+1));
        if(lazy[2*i+1])
            sum[i]=add(sum[i],mul(lazy[2*i+1],r-m));
    }
    int get(int qs,int qe,int l=0,int r=N-1,int i=1){
        if(qs>r||qe<l)
            return 0;
        if(qs<=l&&qe>=r)
            return add(sum[i],mul(lazy[i],r-l+1));
        int m=(l+r)>>1;
        prop(i);
        int sol=add(get(qs,qe,l,m,2*i),get(qs,qe,m+1,r,2*i+1));
        sum[i]=add(sum[2*i],sum[2*i+1]);
        if(lazy[2*i])
            sum[i]=add(sum[i],mul(lazy[2*i],m-l+1));
        if(lazy[2*i+1])
            sum[i]=add(sum[i],mul(lazy[2*i+1],r-m));
        return sol;
    }
}put,dodaj;*/
struct fenwick{
    vector<int> b[2];
    fenwick(){b[0].resize(N);b[1].resize(N);}
    vector<pair<pair<int,int>,int> > op;
    void ad(int bb,int i,int x){
        for(;i<N;i+=i&(-i))
            b[bb][i]=add(b[bb][i],x);
    }
    void sett(int l,int r,int x,bool no=true){
        if(no)
            op.pb({{l,r},x});
        ad(0,l,x);ad(0,r+1,sub(0,x));
        ad(1,l,mul(x,l-1));ad(1,r+1,sub(0,mul(x,r)));
    }
    int sum(int bb,int i){
        int total=0;
        for(;i>0;i-=i&(-i))
            total=add(total,b[bb][i]);
        return total;
    }
    int prefix_sum(int i){
        return sub(mul(sum(0,i),i),sum(1,i));
    }
    int get(int l,int r){
        return sub(prefix_sum(r),prefix_sum(l-1));
    }
    void resetuj(){
        for(auto p:op)
            sett(p.f.f,p.f.s,sub(0,p.s),0);
        op.clear();
    }
}put,dodaj;
int ans,vel,n,a,b,totalWays=1;
vector<vector<int> > graf(N);
vector<int> siz(N),l(N),r(N),inv(N);
vector<bool> marked(N);

void init(int tr,int par){
    siz[tr]=1;
    vel++;
    for(auto p:graf[tr]){
        assert(p>=0&&p<N);
        if(p!=par&&!marked[p])
            init(p,tr),siz[tr]+=siz[p];
    }
}
int findCentroid(int tr,int par){
    for(auto p:graf[tr])
        if(p!=par&&!marked[p]&&siz[p]>vel/2)
            return findCentroid(p,tr);
    return tr;
}

void prosli(int tr,int par,int dep){
    int sumPut=put.get(l[tr],r[tr]),sumDodaj=dodaj.get(l[tr],r[tr]);
    sumPut=mul(sumPut,inv[tr]);
    sumDodaj=mul(sumDodaj,inv[tr]);
    sumPut=mul(sumPut,dep);
    ans=add(ans,sumDodaj);
    ans=add(ans,sumPut);
    for(auto p:graf[tr])
        if(p!=par&&!marked[p])
            prosli(p,tr,dep+1);
}
void dodajSada(int tr,int par,int dep){
    int x=mul(totalWays,inv[tr]);
    put.sett(l[tr],r[tr],x);
    x=mul(x,dep);
    dodaj.sett(l[tr],r[tr],x);
    for(auto p:graf[tr])
        if(p!=par&&!marked[p])
            dodajSada(p,tr,dep+1);
}
void decomp(int tr){
    vel=0;
    init(tr,tr);
    tr=findCentroid(tr,tr);
    marked[tr]=1;
    //Do magic
    put.resetuj();
    dodaj.resetuj();
    for(auto p:graf[tr])
        if(!marked[p])
            prosli(p,p,1),dodajSada(p,p,1);
    int sumDodaj=dodaj.get(l[tr],r[tr]);
    sumDodaj=mul(sumDodaj,inv[tr]);
    ans=add(ans,sumDodaj);
    for(auto p:graf[tr])
        if(!marked[p])
            decomp(p);
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	//srand(time(NULL));
	/*n=1e5;
	for(int i=0;i<n;i++){
        l[i]=rng()%n+1;
        r[i]=rng()%n+1;
        if(l[i]>r[i])
            swap(l[i],r[i]);
        l[i]--,r[i]--,totalWays=mul(totalWays,r[i]-l[i]+1),inv[i]=pwrmod(r[i]-l[i]+1,mod-2);
	}
    for(int i=1;i<n;i++){
        a=i;
        b=i+1;
        a--,b--,graf[a].pb(b),graf[b].pb(a);
    }*/
    scanf("%i",&n);
    for(int i=0;i<n;i++)
        scanf("%i %i",&l[i],&r[i]),totalWays=mul(totalWays,r[i]-l[i]+1),inv[i]=pwrmod(r[i]-l[i]+1,mod-2);
    for(int i=1;i<n;i++)
        scanf("%i %i",&a,&b),a--,b--,graf[a].pb(b),graf[b].pb(a);
    decomp(0);
    printf("%i\n",ans);
    return 0;
}