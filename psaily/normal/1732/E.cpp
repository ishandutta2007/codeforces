
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,n,a) for (int i=(n)-1;i>=(a);i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define make_unique(x) { sort(all(x)); x.resize(unique(all(x))-x.begin()); }
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
mt19937 mrand(time(0));
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef unsigned long long ull;
const int inf=1<<30;
const int mod=998244353;
int rnd(int x) {return mrand()%x;}
// head
const int N=5e4+5;
int n,q,a[N],b[N];

template<class T>
inline void Min(T &a,T b) {if (a>b) a=b;}

int main() {
    //freopen("data.in","r",stdin);
    //freopen("1.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);  
    cout << fixed << setprecision(6);

    VI bs;
    bool flag=false;

    cin >> n >> q;
    rep(i,1,n+1) cin >> a[i];
    rep(i,1,n+1) cin >> b[i],bs.pb(b[i]);


    const int S=200;

    struct block {
        ll res;
        vector<ll> mn;
        int col;
    };
    vector<block> blk(n/S+1);
    vector<ll> val(n+1);

    // blk[i][x] x lcm(b[i],x)/gcd(b[i],x) == min
    vector<VI> fac(N);
    rep(i,1,N) {
        for (int j=i;j<N;j+=i) fac[j].pb(i);
    }

    auto __val=[&](ll a,ll b) {
        ll g=__gcd(a,b);
        return a/g*b/g;
    };

    make_unique(bs);
    vector<int> pos(N);
    vector<vector<ll>> tab(SZ(bs));

    if (SZ(bs)<100) {
        flag=true;
        rep(i,0,SZ(bs)) pos[bs[i]]=i;
        rep(i,0,SZ(bs)) {
            tab[i].resize(N);
            for (int j=1;j<N;j++) tab[i][j]=__val(bs[i],j);
        }
    };
    auto get_val=[&](int a,int b) {
        if (!flag) return __val(a,b);
        else {
            int bid=pos[b];
            return tab[bid][a];
        }    
    };
    
    rep(i,0,n/S+1) {
        blk[i].mn.resize(N,1e18);
        blk[i].col=-1;
        blk[i].res=1e18;

        int l=max(1,i*S),r=min(n,(i+1)*S-1);
        VI v;

        rep(j,l,r+1) v.pb(b[j]);
        make_unique(v);
        for (auto x:v) {
            //debug(e);
            for (auto y:fac[x]) Min(blk[i].mn[y],(ll)x/y);
        }
        for (int g=1;g<N;g++) {
            for (int j=g+g;j<N;j+=g) Min(blk[i].mn[j],blk[i].mn[g]*(j/g));
        }
    }
    rep(i,1,n+1) {
        val[i]=get_val(a[i],b[i]);
        Min(blk[i/S].res,val[i]);
    }   

    //debug(blk[0].mn[12]);


    while (q--) {
        int op,l,r,x;
        cin >> op;

        if (op==1) {
            cin >> l >> r >> x;
            
            auto upd=[&](int x,int y,int c) {
                const int cur=x/S;
                assert(x/S==y/S);
                y=min(y,n);

                if (~blk[cur].col) {
                    rep(i,max(1,cur*S),l+1) val[i]=get_val(blk[cur].col,b[i]);
                    rep(i,r+1,min(n+1,(cur+1)*S)) val[i]=get_val(blk[cur].col,b[i]);
                }
                blk[cur].col=-1;
                blk[cur].res=1e18;

                rep(i,x,y+1) val[i]=get_val(c,b[i]);
                rep(i,max(cur*S,1),min(n+1,(cur+1)*S)) Min(blk[cur].res,val[i]);
            };

            if (l/S==r/S) {
                upd(l,r,x);
            } else {
                int L=l/S+1,R=r/S-1;
                //bug(L),debug(R);
                if (L<=R) {
                    rep(i,L,R+1) {
                        blk[i].col=x;
                        blk[i].res=blk[i].mn[x];
                    }
                } 
                upd(l,L*S-1,x);
                upd((R+1)*S,r,x);
            }

        } else {
            cin >> l >> r;

            ll ans=1e18;

            if (l/S==r/S) {
                const int cur=l/S;
                rep(i,l,r+1) {
                    if (blk[cur].col==-1) ans=min(ans,val[i]);
                    else { ans=min(ans,get_val(b[i],blk[cur].col)); }
                }
            } else {
                int L=l/S+1,R=r/S-1;

                if (L<=R) {
                    rep(i,L,R+1) Min(ans,blk[i].res);
                }
                rep(i,l,L*S) {
                    if (blk[L-1].col==-1) ans=min(ans,val[i]);
                    else ans=min(ans,get_val(b[i],blk[L-1].col));
                }
                rep(i,(R+1)*S,r+1) {
                    if (blk[R+1].col==-1) ans=min(ans,val[i]);
                    else ans=min(ans,get_val(b[i],blk[R+1].col));
                }

            }

            cout << ans << endl;
        }
    }

    //cerr << clock()/1000 << endl;

    return 0;
}

/*
test1

4 4
3 6  9 20
1 12 3 5
2 1 4
2 2 2
1 1 3 12
2 1 3

test2

10 5
43145 44246 6903 38760 48647 1268 43586 4843 49846 15062 
17565 28476 22360 6428 23024 35800 14026 18939 44512 41228 
1 6 8 2570
1 3 9 3606
2 3 6
2 2 2
2 3 9


*/