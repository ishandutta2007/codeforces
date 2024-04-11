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
	node operator/(const double c)const{return node(x/c,y/c);}
}A[1100000],B[1100000];

const double pi=acos(-1);
int n,t,m,xx,l;
int r[1100000],a[1100000];
ll ans[1100000];

void fft(node *A,int f){
	for(int i=0;i<n;i++) if(r[i]<i) swap(A[r[i]],A[i]);
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
	t=n=readint(); xx=readint();
	for(int i=1;i<=n;i++) a[i]=readint()<xx?-1:0;
	for(int i=1;i<=n;i++) a[i]+=a[i-1];
	for(int i=1;i<=n;i++) A[a[i]+n].x++;
	for(int i=1;i<=n;i++) B[n-a[i]].x++;
	A[n].x++; B[n].x++;
	m=n<<2;
	for(n=1;n<=m;n<<=1) l++;
	for(int i=1;i<n;i++) r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
	fft(A,1); fft(B,1);
	for(int i=0;i<n;i++) A[i]=A[i]*B[i];
	fft(A,-1);
	for(int i=0;i<m;i++) ans[i]=(ll)(A[i].x/n+0.5);
	printf("%lld ",(ans[t<<1]-t-1)/2);
	for(int i=1;i<=t;i++) printf("%lld ",ans[(t<<1)+i]);
	printf("\n");
	return 0;
}