#include <cstdio>

typedef long long ll;

ll n,k;
int l;
int m;

ll pow(ll a,ll b){
    if(b==0) return 1;
    if(b==1) return a%m;
    ll ret=pow(a,b/2); ret=ret*ret%m;
    if(b&1) ret=ret*a%m;
    return ret;
}

ll modgood(ll x){ return ((x%m)+2*m)%m; }

struct mat {
    int a,b;
    int c,d;
    mat(int p,int q,int r,int s) { a=p%m; b=q%m; c=r%m; d=s%m; }
    mat operator*(const mat& other){
        return mat((1LL*a*other.a%m + 1LL*b*other.c%m)%m,
                   (1LL*a*other.b%m + 1LL*b*other.d%m)%m,
                   (1LL*c*other.a%m + 1LL*d*other.c%m)%m,
                   (1LL*c*other.b%m + 1LL*d*other.d%m)%m);
    }
};

mat pow(mat a,ll b){
    if(b==0) return mat(1,0,0,1);
    if(b==1) return a;
    mat ret=pow(a,b/2); ret=ret*ret;
    if(b&1) ret=ret*a;
    return ret;
}

ll getFibo(ll th){
    mat base(0,1,0,0);
    mat trans(0,1,1,1);
    return (base*pow(trans,th+2)).a;
}

int main()
{
    scanf("%I64d%I64d%d%d",&n,&k,&l,&m);
    if(l==0){
        if(k || m==1) puts("0");
        else puts("1");
        return 0;
    }
    if(l!=64 && ((unsigned long long)k)>=(1uLL<<l)){
        puts("0"); return 0;
    }
    int i;
    ll ans=1%m;
    for(i=0;i<l;++i){
        if(k&(1LL<<i)){
            ans=modgood(ans*modgood(pow(2,n)-getFibo(n)));
        } else {
            ans=modgood(ans*getFibo(n));
        }
    }
    printf("%I64d\n",ans);
    return 0;
}