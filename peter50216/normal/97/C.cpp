#include<stdio.h>
double in[1100];
int n;
struct XD{
    int x,y;
    double l;
}ed[94000];
int ec;
double dis[1030];
int nn;
inline bool f(double avg){
    int i,j,k;
    for(i=0;i<=nn;i++)dis[i]=0;
    for(i=0;i<=nn+2;i++)for(j=0;j<ec;j++){
	if(dis[ed[j].y]>dis[ed[j].x]+avg-ed[j].l){
	    dis[ed[j].y]=dis[ed[j].x]+avg-ed[j].l;
	}
    }
    for(j=0;j<ec;j++){
	if(dis[ed[j].y]>dis[ed[j].x]+avg-ed[j].l+1e-8){
	    break;
	}
    }
    return j<ec;
}
int main(){
    int i,j;
    scanf("%d",&n);
    for(i=0;i<=n;i++)scanf("%lf",&in[i]);
    nn=n*3;
    for(i=0;i<=nn;i++){
	for(j=0;j<=i&&j<=n;j++){
	    int r=i-j+n-j;
	    if(r<0||r>nn)continue;
	    ed[ec].x=i;
	    ed[ec].y=r;
	    ed[ec].l=in[j];
	    ec++;
	}
    }
    double l=0,r=1;
    for(int k=0;k<40;k++){
	double m=(l+r)/2;
	if(f(m))l=m;
	else r=m;
    }
    printf("%.10lf\n",l);
}