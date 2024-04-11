#include<bits/stdc++.h>

using namespace std;

#define N 3000
const double pi=acos(-1);

int n;
long long ans;
double c[N];
struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){}
	node operator - (const node p) const{
		return node(x-p.x,y-p.y);
	}
	double calc(){return atan2(y,x);}
}a[N];

long long C(int x){
	if (x<2) return 0;
	return x*(x-1)/2;
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d%d",&a[i].x,&a[i].y);
	for (int i=1;i<=n;++i){
		int xb=0;
		for (int j=1;j<=n;++j)
			if (i!=j) c[++xb]=(a[j]-a[i]).calc();
		sort(c+1,c+xb+1);
		for (int i=1,j=1;i<=xb;++i){
			if (c[i]>0) break;
			for (;j<xb&&c[j+1]<c[i]+pi;++j);
			ans+=C(j-i)*C(xb-1-j+i);
		}
		for (int i=xb,j=xb;i;--i){
			if (c[i]<=0) break;
			for (;j>1&&c[j-1]>c[i]-pi;--j);
			ans+=C(i-j)*C(xb-1-i+j);
		}
	}
	printf("%lld\n",ans/2);
	
	return 0;
}