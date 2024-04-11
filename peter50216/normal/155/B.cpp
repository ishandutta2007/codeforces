#include<stdio.h>
#include<algorithm>
using namespace std;
struct XD{
    int p,c;
    void get(){
        scanf("%d%d",&p,&c);
    }
    bool operator<(const XD& b)const{
        return c==b.c?p>b.p:c>b.c;
    }
}in[1010];
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)in[i].get();
    sort(in,in+n);
    int cc=1,t=0;
    for(i=0;i<n;i++){
        t+=in[i].p;
        cc+=-1+in[i].c;
        if(cc==0)break;
    }
    printf("%d\n",t);
}