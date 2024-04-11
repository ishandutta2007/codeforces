#include<stdio.h>
#include<algorithm>
using namespace std;
int x[1010],y[1010],r[1010];
int n;
inline int f(int xx,int yy){
    int i;
    for(i=0;i<n;i++){
        if((x[i]-xx)*(x[i]-xx)+(y[i]-yy)*(y[i]-yy)<=r[i]*r[i])return 0;
    }
    return 1;
}
int main(){
    int xa,ya,xb,yb;
    scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
    if(xa>xb)swap(xa,xb);
    if(ya>yb)swap(ya,yb);
    scanf("%d",&n);
    int i,j;
    for(i=0;i<n;i++){
        scanf("%d%d%d",&x[i],&y[i],&r[i]);
    }
    int s=0;
    for(i=xa;i<=xb;i++)for(j=ya;j<=yb;j++){
        if(i==xa||i==xb||j==ya||j==yb)s+=f(i,j);
    }
    printf("%d\n",s);
}