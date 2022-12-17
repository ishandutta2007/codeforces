#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll readint(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=3e3+5;
int n,R,x[maxn],y[maxn];
bool f[maxn][maxn];
const double pi=acos(-1);
double sqr(double x){
	return x*x;
}
double dist(int a,int b){
	return sqrt(sqr(x[a]-x[b])+sqr(y[a]-y[b]));
}
double adj(double x){
	if(x<=-pi) return x+pi*2;
	else if(x>pi) return x-pi*2;
	else return x;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	R=readint();
	for(int i=1;i<=n;i++){
		x[i]=readint();
		y[i]=readint();
	}
	for(int i=1;i<=n;i++){
		double l1=-pi,r1=pi,l2=pi,r2=-pi;
		auto upd=[&l1,&r1,&l2,&r2](double l,double r){
			if(l<r){
				l1=max(l1,l);
				r1=min(r1,r);
			}
			else{
				l2=min(l2,r);
				r2=max(r2,l);
			}
		};
		for(int j=1;j<=n;j++) if(dist(i,j)>R){
			double a=atan2(y[j]-y[i],x[j]-x[i]),b=asin(R/dist(i,j));
			upd(adj(a-b),adj(a+b));
		}
		for(int j=1;j<=n;j++) if(i!=j){
			double a=adj(atan2(y[j]-y[i],x[j]-x[i]));
			f[i][j]=a>=l1&&a<=r1&&(a<=l2||a>=r2);
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) cnt+=f[i][j]&&f[j][i];
	printf("%d\n",cnt);
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}