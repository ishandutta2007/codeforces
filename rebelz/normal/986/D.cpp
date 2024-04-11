#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	ld x,y;
	node(ld x=0,ld y=0):x(x),y(y){}
	node operator+(const node c)const{return node(x+c.x,y+c.y);}
	node operator-(const node c)const{return node(x-c.x,y-c.y);}
	node operator*(const node c)const{return node(x*c.x-y*c.y,x*c.y+y*c.x);}
}A[1100000],B[1100000];

const int sz=10000;
const ld pi=acos(-1);
const int pw[5]={1,10,100,1000,10000};
int n,l,N;
int r[1100000];
char s[1500005];

void init(int m){
	l=0;
	for(N=1;N<=m;N<<=1) l++;
	for(int i=1;i<N;i++) r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
}

void fft(node *A,int N,int f){
	for(int i=1;i<N;i++) if(i<r[i]) swap(A[i],A[r[i]]);
	for(int i=1;i<N;i<<=1){
		node wn(cos(pi/i),f*sin(pi/i));
		for(int j=0;j<N;j+=(i<<1)){
			node w(1,0);
			for(int k=j;k<j+i;k++,w=w*wn){
				node x=A[k],y=A[k+i]*w;
				A[k]=x+y; A[k+i]=x-y;
			}
		}
	}
	if(f<0){
		for(int i=0;i<N;i++) A[i].x/=N;
	}
}

bool operator<(vector<int> x,vector<int> y){
	if(x.size()<y.size()) return true;
	if(x.size()>y.size()) return false;
	for(int i=x.size()-1;i>=0;i--){
		if(x[i]<y[i]) return true;
		if(x[i]>y[i]) return false;
	}
	return false;
}

vector<int> operator*(vector<int> x,int c){
	for(int i=0;i<x.size();i++) x[i]*=c;
	x.pb(0);
	for(int i=0;i<x.size()-1;i++) x[i+1]+=x[i]/sz,x[i]%=sz;
	if(x.back()==0) x.pop_back();
	return x;
}

vector<int> operator*(vector<int> x,vector<int> y){
	vector<ll> ret(x.size()+y.size()-1);
	init(ret.size());
	for(int i=0;i<N;i++) A[i]=node(i<x.size()?x[i]:0,0);
	for(int i=0;i<N;i++) B[i]=node(i<y.size()?y[i]:0,0);
	fft(A,N,1); fft(B,N,1);
	for(int i=0;i<N;i++) A[i]=A[i]*B[i];
	fft(A,N,-1);
	for(int i=0;i<ret.size();i++) ret[i]=(ll)(A[i].x+0.5);
	for(int i=0;i<ret.size();i++){
		int to=ret[i]/sz;
		if(to&&i==ret.size()-1) ret.pb(to);
		else if(to) ret[i+1]+=to;
		ret[i]%=sz;
	}
	vector<int> ret2(ret.size());
	for(int i=0;i<ret.size();i++) ret2[i]=ret[i];
	return ret2;
}

void qpow(int p,vector<int> &val){
	if(p==0) return (void)(val.pb(1));
	if(p&1){
		qpow(p-1,val);
		val=val*3;
	}
	else{
		qpow(p>>1,val);
		val=val*val;
	}
}

void print(vector<int> x){
	for(int i=x.size()-1;i>=0;i--){
		if(i==x.size()-1) printf("%4d",x[i]);
		else printf("%4d",x[i]);
	}
	printf("\n");
}

int main(){
	scanf("%s",s+1); n=strlen(s+1);
	if(n==1&&s[1]=='1'){
		printf("1\n");
		return 0;
	}
	vector<int> a(0);
	for(int i=n;i>=1;i-=4){
		int now=0;
		for(int j=max(1,i-3);j<=i;j++) now+=(s[j]-'0')*pw[i-j];
		a.pb(now);
	}
	int tmp=log(10)*(n-1)/log(3)-3;
	chkmax(tmp,0);
	int ans=3*tmp;
	vector<int> val(0);
	qpow(tmp,val);
	while(val<a){
		if(!((val*2)<a)){
			ans+=2;
			break;
		}
		else if(!((val*3)<a)){
			ans+=3;
			break;
		}
		else if(!((val*4)<a)){
			ans+=4;
			break;
		}
		else val=val*3,ans+=3;
	}
	printf("%d\n",ans);
	return 0;
}