#include <cstdio>

const int MAXM=1<<17;
const int MOD=998244353;

inline int sum(const int &a, const int &b){
	static int sr;
	sr=a+b;
	if(sr>=MOD)	sr-=MOD;
	return sr;
}

inline int mul(const int &a, const int &b){
	return (int)((1LL*a*b)%(long long)(MOD));
}

int pow(int a, int k){
	int ret=1;
	while(k){
		if(k&1)	ret=mul(ret, a);
		a=mul(a, a);
		k>>=1;
	}
	return ret;
}

inline int norm(const int &v){
	return v%MOD;
}

inline void add(int &f, const int &v){
	f+=v;
	if(f>=MOD)	f-=MOD;
}

int Inv2=(MOD+1)/2;
int N, K, M;
int x, y, z, tot;

int A[MAXM], B[MAXM], C[MAXM], Ans[MAXM];

void FWT(int x[]){
	int l, r;
	for(int i=1;i<M;i<<=1)
		for(int j=0;j<M;j+=(i<<1))
			for(int k=0;k<i;++k){
				l=x[j+k];r=x[j+k+i];
				x[j+k]=sum(l, r);
				x[j+k+i]=sum(l, MOD-r);
			}
}

void IFWT(int x[]){
	int l, r;
	for(int i=1;i<M;i<<=1)
		for(int j=0;j<M;j+=(i<<1))
			for(int k=0;k<i;++k){
				l=x[j+k];r=x[j+k+i];
				x[j+k]=sum(l, r);
				x[j+k+i]=sum(l, MOD-r);
				x[j+k]=mul(x[j+k], Inv2);
				x[j+k+i]=mul(x[j+k+i], Inv2);
			}
}

int main(){
	
	scanf("%d%d", &N, &K);M=1<<K;
	scanf("%d%d%d", &x, &y, &z);
	x=norm(x);y=norm(y);z=norm(z);
	
	for(int i=1, a, b, c;i<=N;++i){
		scanf("%d%d%d", &a, &b, &c);
		b^=a;c^=a;tot^=a;
		++A[b^c];++B[b];++C[c];
	}
	
	FWT(A);FWT(B);FWT(C);
	
	for(int i=0;i<M;++i){
		int a=A[i], b=B[i], c=C[i], d, e, f, g;
		add(a, N);add(b, N);add(c, N);
		a=mul(a, Inv2);b=mul(b, Inv2);c=mul(c, Inv2);
		d=mul(sum(sum(a, sum(b, c)), MOD-N), Inv2);
		e=c-d;f=b-d;g=a-d;
		Ans[i]=1;
		Ans[i]=mul(Ans[i], pow(sum(x, sum(y, z)), d));
		Ans[i]=mul(Ans[i], pow(sum(x, sum(MOD-y, z)), e));
		Ans[i]=mul(Ans[i], pow(sum(x, sum(y, MOD-z)), f));
		Ans[i]=mul(Ans[i], pow(sum(x, sum(MOD-y, MOD-z)), g));
	}
	
	IFWT(Ans);
	
	for(int i=0;i<M;++i)	printf("%d ", Ans[i^tot]);
	puts("");
	
	return 0;
}