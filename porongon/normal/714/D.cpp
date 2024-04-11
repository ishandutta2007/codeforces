#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
#define FF fflush(stdout)
using namespace std;

typedef long long ll;

int query(int x1, int y1, int x2, int y2){
	if(x1>x2)swap(x1,x2);
	if(y1>y2)swap(y1,y2);
	printf("? %d %d %d %d\n",x1,y1,x2,y2);FF;
	int r;
	scanf("%d",&r);
	return r;
}

int main(){
	int n;
	scanf("%d",&n);
	int x0,x1,y0,y1;
	int s=1,e=n+1;
	int nit=0;
	while(e-s>1){
		int m=(s+e)/2;
		if(query(m,1,n,n)==2)s=m;
		else e=m;
		nit++;
	}
	x0=s;
	s=1;e=n+1;
	while(e-s>1){
		int m=(s+e)/2;
		if(query(1,m,n,n)==2)s=m;
		else e=m;
	}
	y0=s;
	s=1;e=n+1;
	while(e-s>1){
		int m=(s+e)/2;
		if(query(1,1,m-1,n)<2)s=m;
		else e=m;
	}
	x1=s;
	s=1;e=n+1;
	while(e-s>1){
		int m=(s+e)/2;
		if(query(1,1,n,m-1)<2)s=m;
		else e=m;
	}
	y1=s;

	int x2,y2,x3,y3;
	s=1,e=n+1;
	while(e-s>1){
		int m=(s+e)/2;
		if(query(m,1,n,n)>=1)s=m;
		else e=m;
	}
	x2=s;
	s=1;e=n+1;
	while(e-s>1){
		int m=(s+e)/2;
		if(query(1,m,n,n)>=1)s=m;
		else e=m;
	}
	y2=s;
	s=1;e=n+1;
	while(e-s>1){
		int m=(s+e)/2;
		if(query(1,1,m-1,n)<1)s=m;
		else e=m;
	}
	x3=s;
	s=1;e=n+1;
	while(e-s>1){
		int m=(s+e)/2;
		if(query(1,1,n,m-1)<1)s=m;
		else e=m;
	}
	y3=s;

	if(query(x0,y0,x3,y3)==1&&query(x2,y2,x1,y1)==1){printf("! %d %d %d %d %d %d %d %d\n",x0,y0,x3,y3,x2,y2,x1,y1);FF;}
	else if(query(x0,y2,x3,y1)==1&&query(x2,y0,x1,y3)==1){printf("! %d %d %d %d %d %d %d %d\n",x0,y2,x3,y1,x2,y0,x1,y3);FF;}

	else if(query(x0,y2,x3,y3)==1&&query(x2,y0,x1,y1)==1){printf("! %d %d %d %d %d %d %d %d\n",x0,y2,x3,y3,x2,y0,x1,y1);FF;}
	else if(query(x0,y0,x3,y1)==1&&query(x2,y2,x1,y3)==1){printf("! %d %d %d %d %d %d %d %d\n",x0,y0,x3,y1,x2,y2,x1,y3);FF;}

	else if(query(x2,y0,x1,y1)==1&&query(x0,y2,x3,y3)==1){printf("! %d %d %d %d %d %d %d %d\n",x2,y0,x1,y1,x0,y2,x3,y3);FF;}
	else if(query(x0,y0,x3,y1)==1&&query(x2,y2,x1,y3)==1){printf("! %d %d %d %d %d %d %d %d\n",x0,y0,x3,y1,x2,y2,x1,y3);FF;}

	else if(query(x0,y2,x1,y1)==1&&query(x2,y0,x3,y3)==1){printf("! %d %d %d %d %d %d %d %d\n",x0,y2,x1,y1,x2,y0,x3,y3);FF;}

	else if(query(x0,y0,x1,y3)==1&&query(x2,y2,x3,y1)==1){printf("! %d %d %d %d %d %d %d %d\n",x0,y0,x1,y3,x2,y2,x3,y1);FF;}




	else if(query(x0,y0,x3,y1)==1&&query(x2,y2,x1,y3)==1){printf("! %d %d %d %d %d %d %d %d\n",x0,y0,x3,y1,x2,y2,x1,y3);FF;}


	else if(query(x2,y0,x1,y3)==1&&query(x0,y2,x3,y1)==1){printf("! %d %d %d %d %d %d %d %d\n",x2,y0,x1,y3,x0,y2,x3,y1);FF;}
	else if(query(x2,y2,x1,y1)==1&&query(x0,y0,x3,y3)==1){printf("! %d %d %d %d %d %d %d %d\n",x2,y2,x1,y1,x0,y0,x3,y3);FF;}
	else {assert(0);}
	return 0;
}