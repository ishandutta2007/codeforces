#include <cstdio>

using namespace std;
#define eps 1e-9

int t0,t1,t2,x1,x2,y1=-1,y2=-1;
double res=1000000000.0;

double f(double n,double m) {
	if (n>0||m>0) return (double)((t1*n+t2*m)/(n+m));
	return 0;
}


void swap(int &a,int &b) {
	int z=a; a=b; b=z; 
}

double abs(double a) {
	if (a>=0) return a; else return -a;
}

void best(int i,int r) {
	if (f(i,r)>=t0&&f(i,r)<res||(abs(f(i,r)-res)<eps&&i+r>y1+y2))
		{res=f(i,r);y1=i;y2=r;};
}

int main() {
	scanf("%d%d%d%d%d",&t1,&t2,&x1,&x2,&t0);
	for (int i=0;i<=x1;i++)
	{ int l=0,r=x2,m=(r+l)/2;  best(i,r); best(i,l); best(i,m); 
	while (l<r) 
	  {
		  m=(r+l)/2;
		  if (f(i,m)<t0) l=m+1; else if (abs(f(i,m)-t0)<eps) break; else r=m;
	  }
	  best(i,r); best(i,l); best(i,m);
	}
	printf("%d %d\n",y1,y2);

	return 0;
}