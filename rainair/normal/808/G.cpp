#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb emplace_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 3e5 + 5;
const int MAXM = 17;
char s[MAXN],t[MAXN];
int n,m;
int nxt[MAXN];

struct CP{
    DB x,y;
    inline CP(DB x=0,DB y=0) : x(x),y(y) {}
    inline CP operator + (const CP &t) const {
        return CP(x+t.x,y+t.y);
    } 
    inline CP operator - (const CP &t) const {
        return CP(x-t.x,y-t.y);
    }
    inline CP operator * (const CP &t) const {
        return CP(x*t.x-y*t.y,x*t.y+y*t.x);
    }
    inline CP conj(){return CP(x,-y);}
}W[MAXM+1][MAXN];
const DB pi = acos(-1);

inline CP Exp(DB x){return CP(cos(x),sin(x));}

int r[MAXN<<2],N;

inline void init(int n){
    N = 1;int len = 0;while(N <= n) N <<= 1,++len;
    FOR(i,0,N-1) r[i] = (r[i>>1]>>1)|((i&1)<<(len-1));
}

inline void prework(){
    for(int n = 2,i = 0;i <= MAXM;++i,n <<= 1) FOR(j,0,n-1) W[i][j] = Exp(j*2*pi/n);
}

inline void FFT(CP A[]){
    FOR(i,0,N-1) if(i < r[i]) std::swap(A[i],A[r[i]]);
    for(int cnt = 0,mid = 1;mid < N;mid <<= 1,++cnt){
        CP *w = W[cnt];
        for(int i = 0;i < N;i += (mid<<1)){
            for(int j = 0;j < mid;++j){
                CP x = A[i+j],y = A[i+mid+j]*w[j];
                A[i+j] = x+y;A[i+mid+j] = x-y;
            }
        }
    }
}

CP tmp[MAXN];

inline void DFT(LL A[],LL B[],CP C[],CP D[]){
    FOR(i,0,N-1) tmp[i] = CP(A[i],B[i]);
    FFT(tmp);
    FOR(i,0,N-1){
        CP x = tmp[i],y = tmp[i?N-i:0].conj();
        C[i] = (x+y)*CP(0.5,0);
        D[i] = (x-y)*CP(0,-0.5);
    }
}

inline void IDFT(CP A[],CP B[],LL C[],LL D[]){
    FOR(i,0,N-1) tmp[i] = A[i]+B[i]*CP(0,1);
    FFT(tmp);std::reverse(tmp+1,tmp+N);
    FOR(i,0,N-1) C[i] = (LL)(tmp[i].x/N+0.5),D[i] = (LL)(tmp[i].y/N+0.5);
}

inline void getkmp(){
    int j = 0;
    FOR(i,2,m){
        while(j && t[i] != t[j+1]) j = nxt[j];
        if(t[i] == t[j+1]) ++j;
        nxt[i] = j;
    }
}

LL S[MAXN],S2[MAXN],T[MAXN],T2[MAXN];
CP A[MAXN],B[MAXN],C[MAXN],D[MAXN];
LL sm[MAXN];

inline int ctoi(char c){
    if(c == '?') return 0;
    return c-'a'+1;
}
bool ok[MAXN];// [i-m+1..i] 

P<int,int> mx[MAXN][35],f[MAXN],qz[MAXN];
char res[MAXN];

int main(){
    /*
    prework();init(2);
    S[0] = 1;S[1] = 2;T[0] = 3;T[1] = 2;
    DFT(S,T,A,B);FOR(i,0,N-1) C[i] = A[i]*B[i];
    IDFT(C,D,S2,T2);
    FOR(i,0,N-1) DEBUG(S2[i]);
    exit(0);*/
//    freopen("match2.in","r",stdin);
    scanf("%s%s",s+1,t+1);n = strlen(s+1);m = strlen(t+1);
    getkmp();prework();init(n+m);
    FOR(i,0,n-1) S[i] = ctoi(s[i+1]),S2[i] = S[i]*S[i];
    FOR(i,0,m-1) T[i] = ctoi(t[i+1]),T2[i] = T[i]*T[i];
    std::reverse(T,T+m);std::reverse(T2,T2+m);
    DFT(S,S2,A,B);DFT(T,T2,C,D);
    FOR(i,0,N-1) A[i] = A[i]*D[i],B[i] = B[i]*C[i];
    IDFT(A,B,S,T);
    FOR(i,0,n-1) sm[i] = (i==0?0:sm[i-1]) + ctoi(s[i+1])*ctoi(s[i+1])*ctoi(s[i+1]);
    FOR(i,0,n-m){
        LL t = S[i+m-1]-2*T[i+m-1]+sm[i+m-1]-(i==0?0:sm[i-1]);
        if(!t) ok[i+m] = 1;
    }
//    FOR(i,1,n) DEBUG(ok[i]);
    std::vector<P<int,int> > S;std::vector<int> B;
    int p = nxt[m];while(p) B.pb(p),p = nxt[p];
    for(int i = 0,j;i < SZ(B);i = j+1){
        j = i;
        if(i+2 >= SZ(B) || B[i+2]-B[i+1] != B[i+1]-B[i]){
            S.pb(B[i],0);
            continue;
        }
        j = i+3;
        while(j < SZ(B) && B[j]-B[j-1] == B[j-1]-B[j-2]) ++j;
        --j;
        S.pb(B[i],B[i]-B[i+1]);
    }
    P<int,int> ans;
    FOR(i,1,n){
        P<int,int> t;
        if(ok[i]){
            f[i] = qz[i-m];
 //           if(i == 6) DEBUG(f[i].fi);
            FOR(j,0,SZ(S)-1){
                if(S[j].fi-m+i >= 1){
                    f[i] = std::max(f[i],mx[S[j].fi-m+i][j]);
                }
            }
            f[i].fi++;t = MP(f[i].fi,i);
        }
        ans = std::max(ans,t);
        qz[i] = std::max(qz[i-1],t);
        FOR(j,0,SZ(S)-1){
            if(i-S[j].se >= 0) mx[i][j] = std::max(t,mx[i-S[j].se][j]);
        }
    }
    printf("%d\n",ans.fi);
    return 0;
}