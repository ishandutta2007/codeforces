#include<cmath>
#include<cstdio>
#include<vector>
using namespace std;
#define eps 1e-6
#define FOR(i,x,y) for(int i=(x),i##_END=(y);i<=i##_END;++i)
typedef double db;

int chk(db x,db y){return (x-y)<=-eps?-1:(x-y)<=eps?0:1;}

const int M=100005;
struct Point{
	db x,y;
	Point operator / (const db &k)const{return (Point){x/k,y/k};}
	Point operator * (const db &k)const{return (Point){x*k,y*k};}
	Point operator + (const Point &_)const{return (Point){x+_.x,y+_.y};}
	Point operator - (const Point &_)const{return (Point){x-_.x,y-_.y};}
}A[M],B[M];

db dist(Point x,Point y){
	return (x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y);
}

vector<db>E;

void Deal1(Point A,Point B,Point a,Point b){// 
	db l=0,r=1;
	FOR(i,1,50){
		db mid=(l+r)*0.5;
		db lm=(mid+l)*0.5,rm=(mid+r)*0.5;
		if(dist(A+a*lm,B+b*lm)>dist(A+a*rm,B+b*rm))r=rm;
		else l=lm;
	}
	E.push_back(dist(A,B));
	E.push_back(dist(A+a*l,B+b*l));
}

void Deal2(Point A,Point B,Point a,Point b){// 
	db l=0,r=1;
	FOR(i,1,50){
		db mid=(l+r)*0.5;
		db lm=(mid+l)*0.5,rm=(mid+r)*0.5;
		db d1=dist(A+a*lm,B+b*lm),d2=dist(A+a*rm,B+b*rm);
		if(d1<d2)r=rm;
		else l=lm;
	}
	E.push_back(dist(A,B));
	E.push_back(dist(A+a*l,B+b*l));
}

int main(){
	
	int n;
	db d1,d2;
	scanf("%d%lf%lf",&n,&d1,&d2);
	
	FOR(i,1,n){
		scanf("%lf%lf",&A[i].x,&A[i].y);
		scanf("%lf%lf",&B[i].x,&B[i].y);
	}
	
	FOR(i,1,n-1){
		db s=dist(A[i],B[i]);
		Point d1=A[i+1]-A[i];
		Point d2=B[i+1]-B[i];
		Point a=A[i]+d1*0.001;
		Point b=B[i]+d2*0.001;
		db s1=dist(a,b);
		if(chk(s,s1)<=0)Deal1(A[i],B[i],d1,d2);
		else Deal2(A[i],B[i],d1,d2);
	}
	E.push_back(dist(A[n],B[n]));
	
	bool f=false;
	int ans=0;
	for(int i=0;i<(int)E.size();++i){
		db y=E[i];
		if(chk(y,d1*d1)<=0){
			if(!f)ans++,f=true;
		}else if(chk(y,d2*d2)>0){
			f=false;
		}
	}
	printf("%d\n",ans);
	return 0;
}