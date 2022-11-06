#include <cstdio>

typedef long long ll;

ll sqrt(ll x) {
    if(x==0) return 0;
    if(x==1) return 1;
    ll l=0, r=x/100+1001, m;
    while(l+1!=r){
        m=(l+r)/2;
        if(m*m<=x) l=m;
        else r=m;
    }
    return l;
}

ll square(ll x) { return x*x; }
ll abs(ll x) { return x>0?x:-x; }

int main()
{
    ll r,x1,y1,x2,y2;
    scanf("%I64d%I64d%I64d%I64d%I64d",&r,&x1,&y1,&x2,&y2);
    x1=square(x1-x2)+square(y1-y2);
    x2=sqrt(x1);
    r*=2;
    y1=x2/r+1;
    if(x2*x2==x1 && !(x2%r)) --y1;
    printf("%I64d\n",y1);
    return 0;
}