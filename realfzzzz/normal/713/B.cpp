#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
int n;
int query(int x1,int y1,int x2,int y2){
	printf("? %d %d %d %d\n",x1,y1,x2,y2);
	fflush(stdout);
	return read();
}
int getx1(int x1,int y1,int x2,int y2){
	int l=x1,r=x2;
	while(l<r){
		int mid=l+(r-l+1)/2;
		if(query(mid,y1,x2,y2)>=1) l=mid;
		else r=mid-1;
	}
	return r;
}
int getx2(int x1,int y1,int x2,int y2){
	int l=x1,r=x2;
	while(l<r){
		int mid=l+(r-l)/2;
		if(query(x1,y1,mid,y2)>=1) r=mid;
		else l=mid+1;
	}
	return r;
}
int gety1(int x1,int y1,int x2,int y2){
	int l=y1,r=y2;
	while(l<r){
		int mid=l+(r-l+1)/2;
		if(query(x1,mid,x2,y2)>=1) l=mid;
		else r=mid-1;
	}
	return r;
}
int gety2(int x1,int y1,int x2,int y2){
	int l=y1,r=y2;
	while(l<r){
		int mid=l+(r-l)/2;
		if(query(x1,y1,x2,mid)>=1) r=mid;
		else l=mid+1;
	}
	return r;
}
int main(){
#ifdef LOCAL
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
#endif
	n=read();
	int x11,y11,x12,y12,x21,y21,x22,y22;
	x12=getx2(1,1,n,n);
	if(x12<n&&query(x12+1,1,n,n)==1){
		x11=getx1(1,1,x12,n);
		y11=gety1(x11,1,x12,n);
		y12=gety2(x11,y11,x12,n);
		x21=getx1(x12+1,1,n,n);
		y21=gety1(x21,1,n,n);
		x22=getx2(x21,y21,n,n);
		y22=gety2(x21,y21,x22,n);
	}
	else{
		y12=gety2(1,1,n,n);
		x11=getx1(1,1,n,y12);
		y11=gety1(x11,1,n,y12);
		x12=getx2(x11,y11,n,y12);
		x21=getx1(1,y12+1,n,n);
		y21=gety1(x21,y12+1,n,n);
		x22=getx2(x21,y21,n,n);
		y22=gety2(x21,y21,x22,n);
	}
	printf("! %d %d %d %d %d %d %d %d\n",x11,y11,x12,y12,x21,y21,x22,y22);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}