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
struct XD{
    int m,v,id;
    bool operator<(const XD& b)const{
        return m==b.m?v>b.v:m>b.m;
    }
}in[101000];
int n,k,h;
int out[101000];
inline bool f(double t,bool f=0){
    int i;
    long long nk=k;
    for(i=0;i<n&&nk;i++){
        if(t*in[i].v>=nk*h){
            if(f)out[nk]=in[i].id;
            nk--;
        }
    }
    if(nk==0)return 1;
    return 0;
}
int main(){
    int i,j;
    scanf("%d%d%d",&n,&k,&h);
    for(i=0;i<n;i++){
        int m;
        scanf("%d",&m);
        in[i].m=m;
    }
    for(i=0;i<n;i++){
        int v;
        scanf("%d",&v);
        in[i].v=v;
        in[i].id=i+1;
    }
    sort(in,in+n);
    double l=0,r=1000000001;
    for(int kk=0;kk<120;kk++){
        double m=(l+r)/2;
        if(f(m))r=m;
        else l=m;
    }
    f(r,1);
    for(i=1;i<=k;i++)printf("%d%c",out[i],(i==k?'\n':' '));
}