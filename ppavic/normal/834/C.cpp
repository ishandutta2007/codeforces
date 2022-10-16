#include <cstdio>
#include <cmath>

using namespace std;

typedef long long int llint;

const llint INF = 1e6;
int n;
llint a,b;

llint llgcd(llint a,llint b){
    if(!a || !b) return a + b;
    if( a < b )
        return llgcd(a,b%a);
    return llgcd(b,a%b);
}


llint treci(llint lo,llint hi,llint x){
    if(lo > hi) return -1;
    llint mid = (lo + hi) / 2;
    if(mid * mid * mid == x){
        return mid;
    }
    else if(mid * mid * mid > x){
        return treci(lo,mid-1,x);
    }
    else{
        return treci(mid+1,hi,x);
    }
}

int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%I64d%I64d",&a,&b);
        llint kor3 = treci(0,INF,a*b);
        llint gcd = llgcd(a,b);
        if(kor3 == -1){
            printf("No\n");
            continue;
        }
        if(gcd%kor3){
            printf("No\n");
            continue;
        }
        llint bla = (a * b) / (gcd * gcd) * kor3;
        if(sqrt(bla) * sqrt(bla) != bla){
            printf("No\n");
            continue;
        }
        printf("Yes\n");
    }
}