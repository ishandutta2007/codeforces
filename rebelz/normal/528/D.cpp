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
int n,m,l,S,T,k;
int r[1100000],ans[1100000];
char ch[5],s[200005],t[200005];

void fft(node *A,int f){
	for(int i=1;i<n;i++) if(r[i]<i) swap(A[r[i]],A[i]);
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
	S=readint(); T=readint(); k=readint();
	m=S+S+T+T,l=0;
	for(n=1;n<=m;n<<=1) l++;
	for(int i=0;i<n;i++) r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
	ch[1]='A'; ch[2]='T'; ch[3]='G'; ch[4]='C';
	scanf("%s%s",s+1,t+1);
	for(int c=1;c<=4;c++){
		for(int i=0;i<n;i++) A[i].x=A[i].y=B[i].x=B[i].y=0;
		for(int i=1;i<=S;i++) A[T+i].x=(s[i]==ch[c]);
		for(int i=1;i<=T;i++) B[T-i].x=(t[i]==ch[c]);
		for(int i=1;i<=S;i++){
			if(A[T+i].x){
				int g=T+i+1;
				for(int j=g;j<=g+k-1&&j<=T+S;j++,i++){
					if(A[j].x) break;
					A[j].x=1;
				}
			}
		}
		for(int i=S;i>=1;i--){
			if(A[T+i].x){
				int g=T+i-1;
				for(int j=g;j>=g-k+1&&j>=T+1;j--,i--){
					if(A[j].x) break;
					A[j].x=1;
				}
			}
		}
		fft(A,1); fft(B,1);
		for(int i=0;i<n;i++) A[i]=A[i]*B[i];
		fft(A,-1);
		for(int i=0;i<m;i++) ans[i]+=(int)(A[i].x/n+0.5);
	}
	int ret=0;
	for(int i=0;i<S;i++) if(ans[T+T+i]==T) ret++;
	printf("%d\n",ret);
	return 0;
}