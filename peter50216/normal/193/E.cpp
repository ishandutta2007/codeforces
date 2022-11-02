#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<stdarg.h>
#include<time.h>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
long long cyc[30];
long long mod;
inline long long add(long long a,long long b){
    a+=b;
    if(a>=mod)a-=mod;
    return a;
}
inline long long mul(long long a,long long b){// a<mod, b<mod
    if(mod<1000000000)return (a*b)%mod;
    long long r=0;
    if(a==0||b==0)return 0;
    while(b){
        if(b&1)r=add(r,a);
        b>>=1;
        a=add(a,a);
    }
    return r;
}
struct XD{
    long long a[2][2];
    XD(){
        memset(a,0,sizeof(a));
    }
    XD operator*(const XD& b)const{
        int i,j,k;
        XD x;
        for(i=0;i<2;i++)for(j=0;j<2;j++)for(k=0;k<2;k++)x.a[i][k]=add(x.a[i][k],mul(a[i][j],b.a[j][k]));
        return x;
    }
};
XD e,id,a,b;
inline long long fib(long long x,long long m){
    if(x==0)return 0;
    x--;
    mod=m;
    a=id;
    b=e;
    while(x){
        if(x&1)a=a*b;
        b=b*b;
        x>>=1;
    }
    return a.a[0][0];
}
char in[10000];
vector<long long> pl[15];
int main(){
    int i,j,k;
    cyc[1]=60;
    cyc[2]=300;
    cyc[3]=1500;
    for(i=3;i<=13;i++)cyc[i]=cyc[i-1]*10;
    e.a[0][0]=e.a[0][1]=e.a[1][0]=1;
    id.a[0][0]=id.a[1][1]=1;
    scanf("%s",in);
    int l=strlen(in);
    long long f=in[l-1]-'0';
    long long po=10;
    for(i=0;i<60;i++)if(fib(i,10)==f)pl[0].push_back(i);
    for(i=1;i<13;i++){
        int s;
        if(i<l)s=in[l-1-i]-'0';
        else s=0;
        f+=s*po;
        po*=10;
        for(j=0;j<cyc[i+1]/cyc[i];j++){
            for(k=0;k<pl[i-1].size();k++){
                long long t=pl[i-1][k]+cyc[i]*j;
                if(fib(t,po)==f)pl[i].push_back(t);
            }
        }
        if(pl[i].size()==0)break;
    }
    if(i<13)puts("-1");
    else printf("%I64d\n",pl[12][0]);
}