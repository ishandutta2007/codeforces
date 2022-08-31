#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e5+10, MOD = 998244353;


namespace maroonrk {
    using ll=long long;
    //#define int ll

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define si(x) int(x.size())
#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif

    template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
    template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

    template<class t> using vc=vector<t>;
    template<class t> using vvc=vc<vc<t>>;

    using pi=pair<int,int>;
    using vi=vc<int>;

    template<class t,class u>
    ostream& operator<<(ostream& os,const pair<t,u>& p){
        return os<<"{"<<p.a<<","<<p.b<<"}";
    }

    template<class t> ostream& operator<<(ostream& os,const vc<t>& v){
        os<<"{";
        for(auto e:v)os<<e<<",";
        return os<<"}";
    }

#define mp make_pair
#define mt make_tuple
#define one(x) memset(x,-1,sizeof(x))
#define zero(x) memset(x,0,sizeof(x))
#ifdef LOCAL
    void dmpr(ostream&os){os<<endl;}
    template<class T,class... Args>
    void dmpr(ostream&os,const T&t,const Args&... args){
        os<<t<<" ";
        dmpr(os,args...);
    }
#define dmp2(...) dmpr(cerr,__LINE__,##__VA_ARGS__)
#else
#define dmp2(...) void(0)
#endif

    using uint=unsigned;
    using ull=unsigned long long;

    template<class t,size_t n>
    ostream& operator<<(ostream&os,const array<t,n>&a){
        return os<<vc<t>(all(a));
    }

    template<int i,class T>
    void print_tuple(ostream&,const T&){
    }

    template<int i,class T,class H,class ...Args>
    void print_tuple(ostream&os,const T&t){
        if(i)os<<",";
        os<<get<i>(t);
        print_tuple<i+1,T,Args...>(os,t);
    }

    template<class ...Args>
    ostream& operator<<(ostream&os,const tuple<Args...>&t){
        os<<"{";
        print_tuple<0,tuple<Args...>,Args...>(os,t);
        return os<<"}";
    }

    template<class t>
    void print(t x,int suc=1){
        cout<<x;
        if(suc==1)
            cout<<"\n";
        if(suc==2)
            cout<<" ";
    }

    ll read(){
        ll i;
        cin>>i;
        return i;
    }

    vi readvi(int n,int off=0){
        vi v(n);
        rep(i,n)v[i]=read()+off;
        return v;
    }

    template<class T>
    void print(const vector<T>&v,int suc=1){
        rep(i,v.size())
            print(v[i],i==int(v.size())-1?suc:2);
    }

    string readString(){
        string s;
        cin>>s;
        return s;
    }

    template<class T>
    T sq(const T& t){
        return t*t;
    }

    //#define CAPITAL
    void yes(bool ex=true){
        #ifdef CAPITAL
        cout<<"YES"<<"\n";
        #else
        cout<<"Yes"<<"\n";
        #endif
        if(ex)exit(0);
    }
    void no(bool ex=true){
        #ifdef CAPITAL
        cout<<"NO"<<"\n";
        #else
        cout<<"No"<<"\n";
        #endif
        if(ex)exit(0);
    }
    void possible(bool ex=true){
        #ifdef CAPITAL
        cout<<"POSSIBLE"<<"\n";
        #else
        cout<<"Possible"<<"\n";
        #endif
        if(ex)exit(0);
    }
    void impossible(bool ex=true){
        #ifdef CAPITAL
        cout<<"IMPOSSIBLE"<<"\n";
        #else
        cout<<"Impossible"<<"\n";
        #endif
        if(ex)exit(0);
    }

    constexpr ll ten(int n){
        return n==0?1:ten(n-1)*10;
    }

    const ll infLL=LLONG_MAX/3;

#ifdef int
    const int inf=infLL;
#else
    const int inf=INT_MAX/2-100;
#endif

    int topbit(signed t){
        return t==0?-1:31-__builtin_clz(t);
    }
    int topbit(ll t){
        return t==0?-1:63-__builtin_clzll(t);
    }
    int botbit(signed a){
        return a==0?32:__builtin_ctz(a);
    }
    int botbit(ll a){
        return a==0?64:__builtin_ctzll(a);
    }
    int popcount(signed t){
        return __builtin_popcount(t);
    }
    int popcount(ll t){
        return __builtin_popcountll(t);
    }
    bool ispow2(int i){
        return i&&(i&-i)==i;
    }
    int mask(int i){
        return (int(1)<<i)-1;
    }

    bool inc(int a,int b,int c){
        return a<=b&&b<=c;
    }

    template<class t> void mkuni(vc<t>&v){
        sort(all(v));
        v.erase(unique(all(v)),v.ed);
    }

    ll rand_int(ll l, ll r) { //[l, r]
        #ifdef LOCAL
        static mt19937_64 gen;
        #else
        static random_device rd;
        static mt19937_64 gen(rd());
        #endif
        return uniform_int_distribution<ll>(l, r)(gen);
    }

    template<class t>
    int lwb(const vc<t>&v,const t&a){
        return lower_bound(all(v),a)-v.bg;
    }

    using uint=unsigned;
    using ull=unsigned long long;

    struct modinfo{uint mod,root;};
    template<modinfo const&ref>
    struct modular{
        static constexpr uint const &mod=ref.mod;
        static modular root(){return modular(ref.root);}
        uint v;
        //modular(initializer_list<uint>ls):v(*ls.bg){}
        modular(ll vv=0){s(vv%mod+mod);}
        modular& s(uint vv){
            v=vv<mod?vv:vv-mod;
            return *this;
        }
        modular operator-()const{return modular()-*this;}
        modular& operator+=(const modular&rhs){return s(v+rhs.v);}
        modular&operator-=(const modular&rhs){return s(v+mod-rhs.v);}
        modular&operator*=(const modular&rhs){
            v=ull(v)*rhs.v%mod;
            return *this;
        }
        modular&operator/=(const modular&rhs){return *this*=rhs.inv();}
        modular operator+(const modular&rhs)const{return modular(*this)+=rhs;}
        modular operator-(const modular&rhs)const{return modular(*this)-=rhs;}
        modular operator*(const modular&rhs)const{return modular(*this)*=rhs;}
        modular operator/(const modular&rhs)const{return modular(*this)/=rhs;}
        modular pow(int n)const{
            modular res(1),x(*this);
            while(n){
                if(n&1)res*=x;
                x*=x;
                n>>=1;
            }
            return res;
        }
        modular inv()const{return pow(mod-2);}
        /*modular inv()const{
            int x,y;
            int g=extgcd(v,mod,x,y);
            assert(g==1);
            if(x<0)x+=mod;
            return modular(x);
        }*/
        friend modular operator+(int x,const modular&y){
            return modular(x)+y;
        }
        friend modular operator-(int x,const modular&y){
            return modular(x)-y;
        }
        friend modular operator*(int x,const modular&y){
            return modular(x)*y;
        }
        friend modular operator/(int x,const modular&y){
            return modular(x)/y;
        }
        friend ostream& operator<<(ostream&os,const modular&m){
            return os<<m.v;
        }
        friend istream& operator>>(istream&is,modular&m){
            ll x;is>>x;
            m=modular(x);
            return is;
        }
        bool operator<(const modular&r)const{return v<r.v;}
        bool operator==(const modular&r)const{return v==r.v;}
        bool operator!=(const modular&r)const{return v!=r.v;}
        explicit operator bool()const{
            return v;
        }
    };

#define USE_FMT


    //in-place fft
    //size of input must be a power of 2
    template<class mint>
    void inplace_fmt_waf(vector<mint>&f,const bool inv){
        const int n=f.size();
        const mint root=inv?mint::root().inv():mint::root();
        vc<mint> g(n);
        for(int b=n/2;b>=1;b/=2){
            mint w=root.pow((mint::mod-1)/(n/b)),p=1;
            for(int i=0;i<n;i+=b*2){
                rep(j,b){
                    f[i+j+b]*=p;
                    g[i/2+j]=f[i+j]+f[i+b+j];
                    g[n/2+i/2+j]=f[i+j]-f[i+b+j];
                }
                p*=w;
            }
            swap(f,g);
        }
        
        if(inv){
            mint z=mint(n).inv();
            rep(i,n)f[i]*=z;
        }
    }


    int rev(int i,int s){
        int j=0;
        rep(k,s)if(i&1<<k)j+=1<<(s-1-k);
        return j;
    }
    template<class mint>
    void inplace_fmt_relka(vector<mint>&f,const bool inv){
        const int n=f.size();
        const mint root=inv?mint::root().inv():mint::root();
        //bitreverse(f);
        //bitreverse(f);
        for(int b=n,s=0;b>>=1;s++){
            //mint w=root.pow((mod-1)/(s*2));
            for(int i=0,idx=0;i<n;i+=b*2,idx++){
                mint p=root.pow(((mint::mod-1)>>(s+1))*rev(idx,s));
                rng(j,i,i+b){
                    mint x=f[j],y=f[j+b]*p;
                    f[j]=x+y;
                    f[j+b]=x-y;
                }
            }
        }
        //bitreverse(f);
        if(inv){
            mint z=mint(n).inv();
            rep(i,n)f[i]*=z;
        }
    }

    //size of input must be a power of 2
    //output of forward fmt is bit-reversed
    //output elements are in the range [0,mod*4)
    //input of inverse fmt should be bit-reversed
    template<class mint>
    void inplace_fmt(vector<mint>&f,bool inv){
        const int n=si(f);
        static vc<mint> g,ig,p2;
        if(si(g)==0){
            rep(i,30){
                mint w=-mint::root().pow(((mint::mod-1)>>(i+2))*3);
                g.pb(w);
                ig.pb(w.inv());
                p2.pb(mint(1<<i).inv());
            }
        }
        static constexpr uint mod2=mint::mod*2;
        if(!inv){
            int b=n;
            if(b>>=1){//input:[0,mod)
                rep(i,b){
                    uint x=f[i+b].v;
                    f[i+b].v=f[i].v+mint::mod-x;
                    f[i].v+=x;
                }
            }
            if(b>>=1){//input:[0,mod*2)
                mint p=1;
                for(int i=0,k=0;i<n;i+=b*2){
                    rng(j,i,i+b){
                        uint x=(f[j+b]*p).v;
                        //f[j].v=(f[j].v<mint::mod?f[j].v:f[j].v-mint::mod);
                        f[j+b].v=f[j].v+mint::mod-x;
                        f[j].v+=x;
                    }
                    p*=g[__builtin_ctz(++k)];
                }
            }
            while(b){
                if(b>>=1){//input:[0,mod*3)
                    mint p=1;
                    for(int i=0,k=0;i<n;i+=b*2){
                        rng(j,i,i+b){
                            uint x=(f[j+b]*p).v;
                            //f[j].v=(f[j].v<mint::mod?f[j].v:f[j].v-mint::mod);
                            f[j+b].v=f[j].v+mint::mod-x;
                            f[j].v+=x;
                        }
                        p*=g[__builtin_ctz(++k)];
                    }
                }
                if(b>>=1){//input:[0,mod*4)
                    mint p=1;
                    for(int i=0,k=0;i<n;i+=b*2){
                        rng(j,i,i+b){
                            uint x=(f[j+b]*p).v;
                            f[j].v=(f[j].v<mod2?f[j].v:f[j].v-mod2);
                            f[j+b].v=f[j].v+mint::mod-x;
                            f[j].v+=x;
                        }
                        p*=g[__builtin_ctz(++k)];
                    }
                }
            }
        }else{
            int b=1;
            if(b<n/2){//input:[0,mod)
                mint p=1;
                for(int i=0,k=0;i<n;i+=b*2){
                    rng(j,i,i+b){
                        ull x=f[j].v+mint::mod-f[j+b].v;
                        f[j].v+=f[j+b].v;
                        f[j+b].v=x*p.v%mint::mod;
                    }
                    p*=ig[__builtin_ctz(++k)];
                }
                b<<=1;
            }
            for(;b<n/2;b<<=1){//input:[0,mod*2)
                mint p=1;
                for(int i=0,k=0;i<n;i+=b*2){
                    rng(j,i,i+b/2){
                        ull x=f[j].v+mod2-f[j+b].v;
                        f[j].v+=f[j+b].v;
                        f[j].v=(f[j].v)<mod2?f[j].v:f[j].v-mod2;
                        f[j+b].v=x*p.v%mint::mod;
                    }
                    rng(j,i+b/2,i+b){
                        ull x=f[j].v+mod2-f[j+b].v;
                        f[j].v+=f[j+b].v;
                        //f[j].v=(f[j].v)<mod2?f[j].v:f[j].v-mod2;
                        f[j+b].v=x*p.v%mint::mod;
                    }
                    p*=ig[__builtin_ctz(++k)];
                }
            }
            if(b<n){//input:[0,mod*2)
                rep(i,b){
                    uint x=f[i+b].v;
                    f[i+b].v=f[i].v+mod2-x;
                    f[i].v+=x;
                }
            }
            mint z=p2[__lg(n)];
            rep(i,n)f[i]*=z;
        }
    }

    template<class mint>
    vc<mint> multiply(vc<mint> x,const vc<mint>&y,bool same=false){
        int n=si(x)+si(y)-1;
        int s=1;
        while(s<n)s*=2;
        x.resize(s);inplace_fmt(x,false);
        if(!same){
            vc<mint> z(s);
            rep(i,si(y))z[i]=y[i];
            inplace_fmt(z,false);
            rep(i,s)x[i]*=z[i];
        }else{
            rep(i,s)x[i]*=x[i];
        }
        inplace_fmt(x,true);x.resize(n);
        return x;
    }

    constexpr modinfo base{998244353,3};
    using mint=modular<base>;
};
using namespace maroonrk;

template<class T> using min_pq = priority_queue<T, vector<T>, greater<T>>;


void solve() {
    int m; cin >> m;
    map<int, int> cnt;
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        cnt[x]++;
    }
    int n = sz(cnt);
    vector<int> a; a.reserve(n);
    for (auto& [_, k] : cnt) a.push_back(k);

    min_pq<pair<int, int>> pq;

    vector<vector<mint>> poly(n);
    for (int i = 0; i < n; i++) {
        poly[i].assign(a[i] + 1, 1);
        pq.push({sz(poly[i]), i});
    }

    while (sz(pq) > 1) {
        auto [s_a, a] = pq.top(); pq.pop();
        auto [s_b, b] = pq.top(); pq.pop();

        poly[a] = multiply(poly[a], poly[b]);
        poly[b].clear();
         
        pq.push({sz(poly[a]), a});
    }

    auto ans = poly[pq.top().second];
    cout << ans[m / 2] << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}