#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define N 300000

const LL mod=1000000007;
LL n,m,op,xb,l,r,c0,c1,c2,f0,f1,f2;
struct node{
	LL x,y,z;
	node(LL x=0,LL y=0,LL z=0):x(x),y(y),z(z){}
	bool operator < (const node p) const{
		return y<p.y;
	}
}a[N];
struct matrix{
	LL s[3][3];
	matrix(){memset(s,0,sizeof s);}
	matrix operator * (const matrix A) const{
		matrix ret;
		for (LL k=0;k<3;++k)
			for (LL i=0;i<3;++i)
				for (LL j=0;j<3;++j)
					ret.s[i][j]=(ret.s[i][j]+s[i][k]*A.s[k][j])%mod;
		return ret;
	}
};

matrix pw(matrix x,LL k){
	if (k==0){
		matrix ret;
		ret.s[0][0]=ret.s[1][1]=ret.s[2][2]=1;
		return ret;
	}
	if (k==1) return x;
	matrix tmp=pw(x*x,k>>1);
	return k&1?tmp*x:tmp;
}

int main(){
	scanf("%lld%lld",&n,&m);
	f0=0; f1=1; f2=0;
	for (LL i=1;i<=n;++i){
		scanf("%lld%lld%lld",&op,&l,&r); --op;
		a[++xb]=node(op,l,1);
		a[++xb]=node(op,r+1,-1);
	}
	sort(a+1,a+xb+1);
	if (a[1].y>2){
		LL nxt=a[1].y;
		matrix mat;
		if (!c0) mat.s[0][0]=mat.s[0][1]=1;
		if (!c1) mat.s[1][0]=mat.s[1][1]=mat.s[1][2]=1;
		if (!c2) mat.s[2][1]=mat.s[2][2]=1;
		mat=pw(mat,nxt-2);
		LL g0,g1,g2;
		g0=mat.s[0][0]*f0+mat.s[0][1]*f1+mat.s[0][2]*f2;
		g1=mat.s[1][0]*f0+mat.s[1][1]*f1+mat.s[1][2]*f2;
		g2=mat.s[2][0]*f0+mat.s[2][1]*f1+mat.s[2][2]*f2;
		f0=g0%mod; f1=g1%mod; f2=g2%mod;
	}
	for (LL i=1;i<=xb;++i){
		if (a[i].x==0) c0+=a[i].z;
		if (a[i].x==1) c1+=a[i].z;
		if (a[i].x==2) c2+=a[i].z;
		if (i==xb||a[i].y!=a[i+1].y){
			LL nxt;
			if (i==xb) nxt=m+1; else nxt=a[i+1].y;
			matrix mat;
			if (!c0) mat.s[0][0]=mat.s[0][1]=1;
			if (!c1) mat.s[1][0]=mat.s[1][1]=mat.s[1][2]=1;
			if (!c2) mat.s[2][1]=mat.s[2][2]=1;
			mat=pw(mat,nxt-a[i].y);
			LL g0,g1,g2;
			g0=mat.s[0][0]*f0+mat.s[0][1]*f1+mat.s[0][2]*f2;
			g1=mat.s[1][0]*f0+mat.s[1][1]*f1+mat.s[1][2]*f2;
			g2=mat.s[2][0]*f0+mat.s[2][1]*f1+mat.s[2][2]*f2;
			f0=g0%mod; f1=g1%mod; f2=g2%mod;
		}
	}
	printf("%lld\n",f1);
	
	return 0;
}