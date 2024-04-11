#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

long double a,b,c,xa,ya,xb,yb,vxa,vya,vxb,vyb;

long double dist(long double xx1,long double yy1,long double xx2,long double yy2){return sqrt((xx1-xx2)*(xx1-xx2)+(yy1-yy2)*(yy1-yy2));}

int main(){
	a=readint(); b=readint(); c=readint(); xa=readint(); ya=readint(); xb=readint(); yb=readint();
	if(a==0||b==0) return printf("%.10Lf\n",fabs(xa-xb)+fabs(ya-yb)),0;
	vxa=(-c-ya*b)/a,vya=(-c-xa*a)/b,vxb=(-c-yb*b)/a,vyb=(-c-xb*a)/b;
	printf("%.10Lf\n",min(fabs(xa-xb)+fabs(ya-yb),min(min(fabs(xa-vxa)+fabs(xb-vxb)+dist(vxa,ya,vxb,yb),fabs(ya-vya)+fabs(xb-vxb)+dist(xa,vya,vxb,yb))
	,min(fabs(xa-vxa)+fabs(yb-vyb)+dist(vxa,ya,xb,vyb),fabs(ya-vya)+fabs(yb-vyb)+dist(xa,vya,xb,vyb)))));
	return 0;
}