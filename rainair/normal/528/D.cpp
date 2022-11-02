#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb push_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 6e5 + 5;
const int ha = 998244353;
const int g = 3;
const int invg = 332748118;

inline int qpow(int a,int n=ha-2){
	int res = 1;
	while(n){
		if(n & 1) res = 1ll*res*a%ha;
		a = 1ll*a*a%ha;
		n >>= 1;
	}
	return res;
}

int r[MAXN],N,n,m,k;

struct Node{
    double x,y;// x+iy
    Node(double x=0,double y=0) : x(x),y(y) {}

    inline Node operator + (const Node &t) const {
        return Node(x+t.x,y+t.y);
    }

    inline Node operator - (const Node &t) const {
        return Node(x-t.x,y-t.y);
    }

    inline Node operator * (const Node &t) const {
        return Node(x*t.x-y*t.y,x*t.y+y*t.x);
    }

    inline Node operator / (const double &t) const {
        return Node(x/t,y/t);
    }

    inline Node conj(){return Node(x,-y);}
};

inline void init(int n){
    int len = 0;N = 1;while(N <= n) N <<= 1,len++;
    FOR(i,0,N-1) r[i] = (r[i>>1]>>1)|((i&1)<<(len-1));
}

const double pi = acos(-1);

inline Node Exp(double x){return Node(cos(x),sin(x));}

inline void FFT(Node A[]){
    FOR(i,0,N-1) if(i < r[i]) std::swap(A[i],A[r[i]]);
    for(int mid = 1;mid < N;mid <<= 1){
        Node W = Exp((2*pi)/(mid<<1));
        for(int i = 0;i < N;i += (mid<<1)){
            Node w(1,0);
            for(int j = 0;j < mid;++j,w = w*W){
                Node x = A[i+j],y = A[i+mid+j]*w;
                A[i+j] = x+y;A[i+mid+j] = x-y;
            } 
        }
    }
}

Node t1[MAXN],t2[MAXN];

inline void mul(int A[],int B[]){
    FOR(i,0,N-1) t1[i] = Node(A[i],B[i]);
//    FOR(i,0,N-1) t2[i] = Node(B[i],0);
    FFT(t1);//FFT(t2);
    FOR(i,0,N-1){
//        t1[i] = t1[i]*t2[i];
        Node x = t1[i],y = t1[i?N-i:0].conj();
        t2[i] = ((x+y)*Node(0.5,0))*((x-y)*Node(0,-0.5));
//        t2[i] = ((x+y)*(y-x).conj())/4;
    }
    FFT(t2);std::reverse(t2+1,t2+N);
    FOR(i,0,n+m-2) A[i] = (int)(t2[i].x/N+0.5);
}

int ans[MAXN],S[MAXN],T[MAXN];
char str[MAXN];
int sm[MAXN][4],occ[MAXN];

inline int ctoi(char x){
    if(x == 'A') return 0;
    if(x == 'G') return 1;
    if(x == 'C') return 2;
    return 3;
}

int A[MAXN],B[MAXN];

inline void gao(int o){
    CLR(A,0);CLR(B,0);
    FOR(i,0,n-1) A[i] = !((occ[i]>>o)&1);
    FOR(i,0,m-1) B[i] = (T[i]==o);
    std::reverse(B,B+m);
    mul(A,B);
//    FOR(i,0,n+m-2) printf("%d ",A[i]);puts("");
    FOR(i,0,n-m) ans[i] |= A[i+m-1];
}

int main(){
    scanf("%d%d%d",&n,&m,&k);init(n+m-2);
    scanf("%s",str);FOR(i,0,n-1) S[i] = ctoi(str[i]);
    scanf("%s",str);FOR(i,0,m-1) T[i] = ctoi(str[i]);
    FOR(i,0,n-1){
        if(i) FOR(j,0,3) sm[i][j] = sm[i-1][j];
        ++sm[i][S[i]];
    }
    FOR(i,0,n-1){
        int l = std::max(0,i-k),r = std::min(n-1,i+k);
        FOR(j,0,3) if(sm[r][j]^(l==0?0:sm[l-1][j])) occ[i] |= (1<<j);
    }
    FOR(i,0,3) gao(i);int res = 0;
    FOR(i,0,n-m) res += (ans[i]==0);
    printf("%d\n",res);
    return 0;
}