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
int n,m,l,k;
int r[2200000],a[2200000],b[2200000];

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

void mul(int *aa,int sa,int *bb,int sb,int *cc,int &sc){
	m=sa+sb,l=0;
	for(n=1;n<=m;n<<=1) l++;
	for(int i=0;i<n;i++) r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
	for(int i=0;i<n;i++) A[i]=node(i<sa?aa[i]:0,0),B[i]=node(i<sb?bb[i]:0,0);
	fft(A,1); fft(B,1);
	for(int i=0;i<n;i++) A[i]=A[i]*B[i];
	fft(A,-1);
	for(int i=0;i<n;i++) cc[i]=i<m?((int)(A[i].x/n+0.5)>0):0;
	sc=m;
}

void solve(int p){
	int sa=1001,sb=1001;
	for(;p;p>>=1,mul(b,sb,b,sb,b,sb)) if(p&1) mul(a,sa,b,sb,a,sa);
}

int main(){
	n=readint(); k=readint();
	int x;
	for(int i=1;i<=n;i++){
		x=readint();
		a[x]++; b[x]++;
	}
	solve(k-1);
	for(int i=0;i<=1000000;i++) if(a[i]) printf("%d ",i);
	printf("\n");
	return 0;
}