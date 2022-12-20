#include <stdio.h>
#include <algorithm>
int mix=23333,miy=23333,mxx=0,mxy=0;
struct pos{
	int x,y;
}p[3];
bool cmp(pos a,pos b){
	return a.y<b.y;
}
int main(){
	for(int i=0;i<3;i++){
		scanf("%d%d",&p[i].x,&p[i].y);
		mix=std::min(mix,p[i].x);
		mxx=std::max(mxx,p[i].x);
		miy=std::min(miy,p[i].y);
		mxy=std::max(mxy,p[i].y);
	}
	std::sort(p,p+3,cmp);
	printf("%d\n",mxx-mix+mxy-miy+1);
	for(int i=mix;i<=mxx;i++)
		printf("%d %d\n",i,p[1].y);
	for(int i=p[0].y;i<p[1].y;i++)
		printf("%d %d\n",p[0].x,i);
	for(int i=p[0].y;i>p[1].y;i--)
		printf("%d %d\n",p[0].x,i);
	for(int i=p[2].y;i<p[1].y;i++)
		printf("%d %d\n",p[2].x,i);
	for(int i=p[2].y;i>p[1].y;i--)
		printf("%d %d\n",p[2].x,i);
}