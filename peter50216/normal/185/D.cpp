#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<stdarg.h>
#include<time.h>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
long long k;
long long l,r;
int p;
inline long long pow(long long a,long long b,long long m){
    if(b==0)return 1%m;
    if(b==1)return a%m;
    long long s=pow(a,b/2,m);
    s=(s*s)%m;
    if(b%2)s=(s*a)%m;
    return s;
}
inline long long rev(long long a,long long b){
    return pow(a,b-2,b);
}
inline int solve(){
    if(p==2){
        if(k%2==0)return 1;
        else return 0;
    }
    //if(k%p==0)return 1;
    long long x=pow(k,pow(2,l,p-1),p);
    long long a;
    if(x%p!=1){
        a=((pow(x,pow(2,r-l+1,p-1),p)+p-1)*rev(x+p-1,p))%p;
    }else{
        a=pow(2,r-l+1,p);
    }
    if(k%p==0)a=1;
    //printf("x=%I64d %I64d\n",x,a);
    if(k%2==1&&r>l){
        a=(a*rev(pow(2,r-l,p),p))%p;
    }
    return a;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%I64d%I64d%I64d%d",&k,&l,&r,&p);
        printf("%d\n",solve());
    }
}