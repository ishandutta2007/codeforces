#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

struct io{
	char ibuf[1<<26],*s,obuf[1<<26],*t;
	int a[25];
	io():t(obuf){
		fread(s=ibuf,1,1<<26,stdin);
	}
	~io(){
		fwrite(obuf,1,t-obuf,stdout);
	}
	inline int read(){
		register int u=0,ty=1;
		while(*s<48) (*s=='-')?ty*=-1:0,s++;
		while(*s>32) u=u*10+*s++-48;
		return u*ty;
	}
	template<class T>
	inline void print(T u,int v){
		print(u);
		*t++=v;
	}
	template<class T>
	inline void print(register T u){
		static int *q=a;
		if(!u) *t++=48;
		else{
			if(u<0)
				*t++=45,u*=-1;
			while(u) *q++=u%10+48,u/=10;
			while(q!=a)
				*t++=*--q;
		}
	}
}ip;

int n,k;
int s[4005][4005],d[805][4005],a[4005][4005],q[4005];

int solve(int x,int y){return (s[y][y]-s[x][y]-s[y][x]+s[x][x])/2;}

int calc(int x,int y,int now){
	int l=y+1,r=n,ans=n+1;
	while(l<=r){
		int mid=(l+r)/2;
		if(d[now-1][x]+solve(x,mid)>=d[now-1][y]+solve(y,mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	return ans;
}

int main(){
	n=ip.read(); k=ip.read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=ip.read();
			s[i][j]=s[i][j-1]+s[i-1][j]-s[i-1][j-1]+a[i][j];
		}
	}
	for(int i=1;i<=n;i++) d[0][i]=1<<30;
	d[0][0]=0;
	for(int i=1;i<=k;i++){
		int front=0,rear=0;
		q[rear++]=0;
		for(int j=1;j<=n;j++){
			while(front+1<rear&&calc(q[front],q[front+1],i)<=j) front++;
			d[i][j]=d[i-1][q[front]]+solve(q[front],j);
			while(front+1<rear&&calc(q[rear-2],q[rear-1],i)>=calc(q[rear-1],j,i)) rear--;
			q[rear++]=j;
		}
	}
	printf("%d\n",d[k][n]);
	return 0;
}