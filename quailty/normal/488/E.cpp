#include<cstdio>
#include<cmath>
typedef long long ll;
ll r[100001];
void gcd(ll a,ll b, ll &d,ll &x,ll &y)
{
    if(!b){
        d=a;x=1;y=0;
    }
    else{
        gcd(b,a%b,d,y,x);
        y-=a/b*x;
    }
}
ll inv(ll a,ll n)
{
    ll d,x,y;
    gcd(a,n,d,x,y);
    return d==1?(x%n+n)%(n/d):-1;
}
int main()
{
    ll n;
    scanf("%I64d",&n);
    if(n==1)printf("YES\n1\n");
    else if(n==2)printf("YES\n1\n2\n");
    else if(n==4)printf("YES\n1\n3\n2\n4\n");
    else{
        ll i;
        for(i=2;i<=(ll)sqrt(n);i++)
            if(n%i==0)break;
        if(i<=(ll)sqrt(n))printf("NO\n");
        else{
            r[0]=1;
            for(ll i=1;i<=n-1;i++){
                r[i]=inv(i,n);
            }
            printf("YES\n");
            for(ll i=1;i<=n-1;i++){
                printf("%I64d\n",(i*r[i-1])%n);
            }
            printf("%d\n",n);
        }
    }
    return 0;
}