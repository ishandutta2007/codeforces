#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
long long in[200100];
long long len[201000];
int main(){
    int n,i,j;
    long long l,v1,v2;
    scanf("%d%I64d%I64d%I64d",&n,&l,&v1,&v2);
    long long w=l*v2;
    l*=v1+v2;
    for(i=0;i<n;i++){
        scanf("%I64d",&in[i]);
        in[i]*=v1+v2;
        in[n+1+i]=in[i]+2*l;
    }
    in[n]=2*l;
    in[2*n+1]=4*l;
    //printf("l=%I64d w=%I64d\n",l,w);
    //for(i=0;i<=2*n;i++)printf("%d %I64d\n",i,in[i]);
    int c=0;
    long long np=0;
    j=0;
    for(i=0;i<n;i++){
        if(in[i]<w)c++;
        else break;
    }
    while(j<=n){
        //printf("i=%d j=%d np=%I64d c=%d\n",i,j,np,c);
        if(in[j]<=in[i]-w){
            len[c]+=in[j]-np;
            np=in[j];
            if(j!=n)c--;
            j++;
        }else{
            len[c]+=in[i]-w-np;
            np=in[i]-w;
            if(i!=n)c++;
            i++;
        }
    }
    for(i=0;i<=n;i++)printf("%.20lf\n",(double)len[i]/(2*l));
}