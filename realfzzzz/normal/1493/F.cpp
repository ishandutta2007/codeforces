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
bool query(int h,int w,int x1,int y1,int x2,int y2){
	printf("? %d %d %d %d %d %d\n",h,w,x1,y1,x2,y2);
	fflush(stdout);
	return read();
}
int main(){
#ifdef LOCAL
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
#endif
	int n,m;
	n=read();
	m=read();
	int x=n,r=n;
	for(int i=2;x>1;i++) while(x%i==0){
		if(i!=2){
			int x=r/i,y=(i-1)/2;
			if(query(x*y,m,1,1,x*(y+1)+1,1)&&query(x*y,m,x+1,1,x*(y+1)+1,1)) r/=i;
		}
		else if(query(r/2,m,1,1,r/2+1,1)) r/=2;
		x/=i;
	}
	int c=x=m;
	for(int i=2;x>1;i++) while(x%i==0){
		if(i!=2){
			int x=c/i,y=(i-1)/2;
			if(query(n,x*y,1,1,1,x*(y+1)+1)&&query(n,x*y,1,x+1,1,x*(y+1)+1)) c/=i;
		}
		else if(query(n,c/2,1,1,1,c/2+1)) c/=2;
		x/=i;
	}
	n/=r;
	r=0;
	for(int i=1;i<=n;i++) r+=n%i==0;
	m/=c;
	c=0;
	for(int i=1;i<=m;i++) c+=m%i==0;
	printf("! %d\n",r*c);
	fflush(stdout);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}