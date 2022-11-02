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
struct XD{
    long long k;
    int c;
    void get(){
        scanf("%I64d%d",&k,&c);
    }
    bool operator<(const XD& b)const{
        return c<b.c;
    }
}in[110];
long long pi[110];
int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)in[i].get();
    sort(in,in+n);
    int t;
    scanf("%d",&t);
    for(i=1;i<=t;i++)scanf("%I64d",&pi[i]);
    long long ans=0;
    long long ct=1;
    long long cq=0;
    for(i=0;i<n;i++){
        while(in[i].k){
            long long x;
            bool f=0;
            if(ct==t+1||cq+in[i].k<=pi[ct]){
                x=in[i].k;
            }else{
                x=pi[ct]-cq;
                f=1;
            }
            cq+=x;
            in[i].k-=x;
            ans+=x*ct*in[i].c;
            if(f)ct++;
        }
    }
    printf("%I64d\n",ans);
}