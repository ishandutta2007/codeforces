#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
typedef long long LL;
typedef long double ld;
typedef pair<int,int> pii;

int n;
LL Ans;
int X1[1001],Y1[1001],X2[1001],Y2[1001];

map<pii,int> m;

struct vec{
	ld x,y;
	friend ld operator/(vec a,vec b){return a.x*b.y-a.y*b.x;}
	friend vec operator-(vec a,vec b){return (vec){a.x-b.x,a.y-b.y};}
	friend vec operator+(vec a,vec b){return (vec){a.x+b.x,a.y+b.y};}
	friend vec operator*(vec a,ld b){return (vec){a.x*b,a.y*b};}
};
struct line{
	vec x,y;
}a[1001];
vec sol(line x,line y){
	vec u=x.x-y.x;
	double t=(y.y/u)/(x.y/y.y);
	return x.x+x.y*t;
}

pii seg(int i,int j,int&ok){
	if(max(X1[i],X2[i])<min(X1[j],X2[j])||max(X1[j],X2[j])<min(X1[i],X2[i])) {ok=0; return pii(0,0);}
	if(max(Y1[i],Y2[i])<min(Y1[j],Y2[j])||max(Y1[j],Y2[j])<min(Y1[i],Y2[i])) {ok=0; return pii(0,0);}
	
	vec S = sol(a[i],a[j]);
	
	if(fabs(S.x-floor(S.x+0.5))>1e-9) {ok=0; return pii(0,0);}
	if(fabs(S.y-floor(S.y+0.5))>1e-9) {ok=0; return pii(0,0);}
	
	LL X=S.x+0.5,Y=S.y+0.5;
	if(S.x<-0.2) --X;
	if(S.y<-0.2) --Y;
	
	if(min(X1[i],X2[i])<=X&&X<=max(X1[i],X2[i]) &&
	min(Y1[i],Y2[i])<=Y&&Y<=max(Y1[i],Y2[i]) &&
	min(X1[j],X2[j])<=X&&X<=max(X1[j],X2[j]) &&
	min(Y1[j],Y2[j])<=Y&&Y<=max(Y1[j],Y2[j])
	) {ok=1; return pii(X,Y);}
	else {ok=0; return pii(0,0);}
}

int main(){
	scanf("%d",&n);
	F(i,1,n){
		scanf("%d%d%d%d",X1+i,Y1+i,X2+i,Y2+i);
		Ans+=__gcd(abs(X1[i]-X2[i]),abs(Y1[i]-Y2[i]))+1;
		a[i].x.x=X1[i], a[i].x.y=Y1[i];
		a[i].y.x=X2[i]-X1[i], a[i].y.y=Y2[i]-Y1[i];
	}
	F(i,1,n){
		F(j,i+1,n){
			int ok;
			pii A=seg(i,j,ok);
			if(ok){
				++m[A];
			}
		}
	}
	for(map<pii,int>::iterator i=m.begin();i!=m.end();++i){
		Ans-=(int)(sqrt(i->second*2));
	}
	printf("%lld\n",Ans);
	return 0;
}