#include<cmath>
#include<cstdio>
#define x1 xxx
#define y1 yyy
int r,x1,y1,x2,y2;
double ansx,ansy,ansr,ans=-1;
void work(double x,double y){
	double v=(x-x2)*(x-x2)+(y-y2)*(y-y2); if(v>ans){
		ans=v; ansx=(x+x2)/2; ansy=(y+y2)/2; ansr=sqrt(v)/2;
	}
}
int main(){
	scanf("%d%d%d%d%d",&r,&x1,&y1,&x2,&y2);
	double deltx=x2-x1,delty=y2-y1,dist=sqrt(deltx*deltx+delty*delty);
	if(dist>=r){
		printf("%d %d %d",x1,y1,r); return 0;	
	}
	if(x1==x2&&y1==y2){
		printf("%.15lf %.15lf %.15lf\n",x1+r/2.0,y1+0.0,r/2.0);
		return 0;
	}
	deltx=deltx/dist*r; delty=delty/dist*r;
	double xx=x1+deltx,yy=y1+delty;
	work(xx,yy); work(x1*2-xx,y1*2-yy);
	printf("%.15lf %.15lf %.15lf",ansx,ansy,ansr);
}