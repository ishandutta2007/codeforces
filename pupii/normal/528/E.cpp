#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
struct vector{double x,y;};
struct line{double k,b;}lns[3010],qaq[3010];
il vector operator+(const vector&a,const vector&b){return(vector){a.x+b.x,a.y+b.y};}
il vector operator-(const vector&a,const vector&b){return(vector){a.x-b.x,a.y-b.y};}
il double operator^(const vector&a,const vector&b){return a.x*b.y-a.y*b.x;}
il vector cross(line a,line b){
	double crx;
	if(std::isinf(a.k))std::swap(a,b),crx=b.b;
	else if(std::isinf(b.k))crx=b.b;
	else crx=(a.b-b.b)/(b.k-a.k);
	double cry=crx*a.k+a.b;
	return (vector){crx,cry};
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi();
	srand(time(NULL));
	for(int i=1;i<=n;++i){
		int a=gi(),b=gi(),c=gi();
		double _k=-1.0*a/b,_b=1.0*c/b;
		if(b==0)_k=1./0,_b=1.0*c/a;
		lns[i]={_k,_b};
	}
	vector O={-2e6,-2e6};
	double ans=0;
	for(int i=1;i<=n;++i){
		double K=lns[i].k;
		int m=0;
		for(int j=1;j<=n;++j)if(j!=i)qaq[++m]=lns[j];
		std::sort(qaq+1,qaq+m+1,[&](line a,line b){
				if((a.k>K)^(b.k>K))return a.k<K;
				return a.k>b.k;
			});
		vector sum={0,0};
		for(int j=1;j<=m;++j){
			vector crs=cross(lns[i],qaq[j])-O;
			ans+=crs^sum;sum=sum+crs;
		}
	}
	printf("%.10lf\n",ans/2/(1ll*n*(n-1)*(n-2)/6));
	return 0;
}