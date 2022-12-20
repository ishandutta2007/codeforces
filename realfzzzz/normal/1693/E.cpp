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
const int maxn=2e5+5;
int n,a[maxn],c1[maxn],c2[maxn];
const int inf=2e9;
struct matrix{
	int a[2][2];
	matrix operator *(matrix B){
		matrix C;
		for(int i=0;i<2;i++) for(int j=0;j<2;j++){
			C.a[i][j]=inf;
			for(int k=0;k<2;k++)
				if(a[i][k]<inf&&B.a[k][j]<inf)
					C.a[i][j]=min(C.a[i][j],a[i][k]+B.a[k][j]);
		}
		return C;
	}
};
matrix get(int x){
	matrix A;
	if(x&1) A.a[0][0]=A.a[1][0]=1;
	else{
		A.a[0][0]=0;
		A.a[1][0]=inf;
	}
	if(x>>1&1) A.a[0][1]=A.a[1][1]=1;
	else{
		A.a[0][1]=inf;
		A.a[1][1]=0;
	}
	return A;
}
struct node{
	int l,r;
	node* ch[2];
	matrix P;
	void pushup(){
		P=ch[0]->P*ch[1]->P;
	}
	node(int l,int r):l(l),r(r){
		if(l==r){
			P=get(c2[r]?2:0);
			return;
		}
		int mid=l+(r-l)/2;
		ch[0]=new node(l,mid);
		ch[1]=new node(mid+1,r);
		pushup();
	}
	void modify(int x,int k){
		if(l==r){
			P=get(k);
			return;
		}
		if(x<=ch[0]->r) ch[0]->modify(x,k);
		else ch[1]->modify(x,k);
		pushup();
	}
	matrix query(int ql,int qr){
		if(ql>r||qr<l){
			matrix A;
			A.a[0][0]=A.a[1][1]=0;
			A.a[0][1]=A.a[1][0]=inf;
			return A;
		}
		if(ql<=l&&qr>=r) return P;
		return ch[0]->query(ql,qr)*ch[1]->query(ql,qr);
	}
}*rt;
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	for(int i=1;i<=n;i++) c2[a[i]=read()]++;
	rt=new node(1,n);
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(a[i-1]){
			c1[a[i-1]]++;
			c2[a[i-1]]--;
			rt->modify(a[i-1],(c1[a[i-1]]?1:0)|(c2[a[i-1]]?2:0));
		}
		if(a[i]==1) ans++;
		else if(a[i]>1){
			matrix A=rt->query(1,a[i]-1);
			ans+=min({A.a[0][0],A.a[0][1],A.a[1][0],A.a[1][1]})+1;
		}
	}
	printf("%lld\n",ans);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}