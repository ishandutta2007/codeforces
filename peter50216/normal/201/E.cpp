// @author peter50216
// #includes {{{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<stdarg.h>
#include<time.h>
#include<ctype.h>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
// }}}
const long long INF=100000000000ll;
inline long long mul(long long a,long long b){
    if(a==0||b==0)return 0;
    if(b>INF/a)return INF;
    a*=b;
    return min(INF,a);
}
inline long long bin(int a,int b){// C(a,b)
    if(b>a||b<0)return 0;
    if(b+b>=a)b=a-b;
    int i;
    long long x=1;
    for(i=1;i<=b;i++){
        x=mul(x,a-i+1);
        if(x>=INF)return INF;
        x/=i;
    }
    return x;
}
inline long long pow2(long long x){
    if(x>=60)return INF;
    x=(1ll<<x);
    return min(INF,x);
}
long long m;
inline long long solve(long long k){
    if(pow2(k-1)<=m)return pow2(k);
    long long r=1,s=0;
    for(int i=1;i<=k;i++){
        long long x=bin(k-1,i-1);
        if(s+x>m){
            s=m-s;
            if(s){
                if(INF*i/k/s==0)return INF;
                r+=k*s/i;
            }
            break;
        }
        s+=x;
        r+=bin(k,i);
    }
    return r;
}
int main(){
    int t;
    scanf("%d",&t);
    long long n;
    while(t--){
        scanf("%I64d%I64d",&n,&m);
        if(m>n)m=n;
        long long l=0,r=n;
        while(l<r){
            long long x=(l+r)/2;
            if(solve(x)>=n)r=x;
            else l=x+1;
        }
        printf("%I64d\n",l);
    }

}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread