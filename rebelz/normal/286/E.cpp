#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	double x,y;
	node(double xx=0,double yy=0):x(xx),y(yy){}
	node operator+(const node c)const{return node(x+c.x,y+c.y);}
	node operator-(const node c)const{return node(x-c.x,y-c.y);}
	node operator*(const node c)const{return node(x*c.x-y*c.y,x*c.y+y*c.x);}
}A[2200000],B[2200000];

const double pi=acos(-1);
int n,m,l,cnt;
int r[2200000],a[1000005],ans[2000005];

void fft(node *A,int f){
	for(int i=0;i<n;i++) if(i<r[i]) swap(A[i],A[r[i]]);
	for(int i=1;i<n;i<<=1){
		node wn(cos(pi/i),f*sin(pi/i));
		for(int j=0;j<n;j+=(i<<1)){
			node w(1,0);
			for(int k=j;k<j+i;k++,w=w*wn){
				node x=A[k],y=w*A[k+i];
				A[k]=x+y; A[k+i]=x-y;
			}
		}
	}
}

int main(){
	n=readint(); m=readint();
	int maxa=0;
	for(int i=1;i<=n;i++){
		a[i]=readint();
		A[a[i]].x++,B[a[i]].x++;
	}
	m=2*m;
	for(n=1;n<=m;n<<=1) l++;
	for(int i=0;i<n;i++) r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
	fft(A,1);
	for(int i=0;i<n;i++) A[i]=A[i]*A[i];
	fft(A,-1);
	for(int i=0;i<n;i++) A[i].x=(int)(A[i].x/n+0.5);
	
	for(int i=1;i<=m/2;i++){
		if(!B[i].x&&A[i].x) return printf("NO\n"),0;
		else if(!A[i].x&&B[i].x) ans[++cnt]=i;
	}
	printf("YES\n%d\n",cnt);
	for(int i=1;i<=cnt;i++) printf("%d ",ans[i]);
	return 0;
}