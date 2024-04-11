#include<cstdio>
#include<algorithm>
using namespace std;
int x1,y1,x2,y2;
int main(){
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	if(x1!=x2&&y1!=y2)printf("%d\n",(abs(x1-x2)+2+abs(y1-y2))*2);
	else printf("%d\n",(abs(x1-x2)+2+abs(y1-y2))*2+2);
}