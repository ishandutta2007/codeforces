#include<stdio.h>
#include<algorithm>
using namespace std;
long long x1,x2,a,b;
inline int solve(long long& winm){
    if(x2-x1<=b&&x2-x1>=a){
        // one step
        winm = x2;
        return 1;
    }
    bool ref=0;
    if(b<=0){
        a*=-1;b*=-1;x1*=-1;x2*=-1;
        swap(a,b);
        ref=1;
    }
    if(a>0){
        if(x1>x2)return 0;
        long long tot=a+b;
        long long r=x2-x1;
        long long s=r%tot;
        if(s==0)return -1;
        if(s>=a&&s<=b){
            winm=s+x1;
            if(ref)winm*=-1;
            return 1;
        }
        return 0;
    }
    return 0;
}
int main(){
    scanf("%I64d%I64d%I64d%I64d",&x1,&x2,&a,&b);
    if(a>b)swap(a,b);
    long long f;
    int d=solve(f);
    puts(d==0?"DRAW":d==-1?"SECOND":"FIRST");
    if(d==1)printf("%I64d\n",f);
}