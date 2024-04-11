#include <cstdio>
#include <cmath>
#include <algorithm>

using std::max;
using std::min;
using std::swap;
using std::lower_bound;

const int MAXN=200011;
const int MAXM=200011;

int Low[65536];

const double PI=acos(-1.0);

int N, D, M;
int A[MAXN];
int Q[MAXM];

void Show(double a){
	printf("%.12lf\n", a);
}

double Tag(int k){
	return atan2(1.0, (double)(k));
}

void Show_(int k){
	Show(Tag(k));
}

void Show__(int k){
	Show(2.0*Tag(k));
}

bool Fetch(int p){
	int r=lower_bound(A+1, A+N+1, p)-A;
	bool ret=false;
	if(r>1)	ret|=(A[r-1]+1)==p;
	if(r<=N)	ret|=(A[r]==p);
	return ret;
}

int lowbit_(int k){
	return ((k&65535)!=0)?Low[k&65535]:(Low[k>>16]+16);
}

struct Bitset{
	int v[300];
	int lowbit(){
		int ret=666666;
		for(int i=0;i<300;++i){
			if(v[i]){
				ret=min(ret, lowbit_(v[i])+i*30);
				break;
			}
		}
		return ret;
	}
	void set(int p){
		//printf("%d\n", p);
		v[p/30]|=(1<<(p%30));
	}
};

Bitset operator >> (Bitset B, int k){
	int t;
	t=k/30;
	for(int i=0;i<300;++i){
		B.v[i]=(i+t<300)?B.v[i+t]:0;
	}
	t=k%30;
	//B.v[-1]=B.v[300]=0;
	//printf("0-%d\n", B.v[0]);
	for(int i=0;i<300;++i){
		B.v[i]=(B.v[i]>>t)|((((1<<t)-1)&((i==299)?0:B.v[i+1]))<<(30-t));
	}
	//printf("1-%d\n", B.v[0]);
	return B;
}

Bitset operator << (Bitset B, int k){
	int t;
	t=k/30;
	for(int i=299;i>=0;--i){
		B.v[i]=(i-t)>=0?B.v[i-t]:0;
	}
	t=k%30;
	for(int i=299;i>=0;--i){
		B.v[i]=((((1<<(30-t))-1)&B.v[i])<<t)|(((i==0)?0:B.v[i-1])>>(30-t));
	}
	return B;
}

Bitset operator & (Bitset &A, Bitset &B){
	Bitset ret;
	for(int i=0;i<300;++i)	ret.v[i]=A.v[i]&B.v[i];
	//for(int i=0;i<3;++i)	printf("%d %d %d\n", A.v[i], B.v[i], ret.v[i]);
	return ret;
}

inline bool Norm(const int &p){
	return p>=0 && p<=8500;
}

struct Data{
	Bitset Lb, Rb;
	int l, p, r;
	double val(){
		int k=(Lb&Rb).lowbit();
		//printf("\t%d\n", k);
		return (k>=666666)?0.0:2.0*Tag(k);
	}
	void move(int t){
		//printf("!%d\n", t-p);
		//printf("%d\n", Rb.v[0]);
		Lb=Lb<<(t-p);Rb=Rb>>(t-p);
		//printf("%d\n", Rb.v[0]);
		p=t;
		if(l && Norm(p-A[l]))	Lb.set(p-A[l]);
		if(l && Norm(p-(A[l]+1)))	Lb.set(p-(A[l]+1));
		while(l<N && A[l+1]<=p){
			++l;
			if(Norm(p-A[l]))	Lb.set(p-A[l]);
			if(Norm(p-(A[l]+1)))	Lb.set(p-(A[l]+1));
		}
		if(r && Norm(A[r]-p))	Rb.set(A[r]-p);
		if(r && Norm((A[r]+1)-p))	Rb.set((A[r]+1)-p);
		while(r<N && A[r+1]<=p+8500){
			++r;
			if(Norm(A[r]-p))	Rb.set(A[r]-p);
			if(Norm((A[r]+1)-p))	Rb.set((A[r]+1)-p);
		}
	}
} Da;

int main(){
	
	for(int i=1;i<65536;++i)	Low[i]=(i&1)?0:(Low[i>>1]+1);
	
	scanf("%d%d", &N, &D);
	for(int i=1;i<=N;++i)	scanf("%d", &A[i]);
	scanf("%d", &M);
	for(int i=1;i<=M;++i)	scanf("%d", &Q[i]);
	
	for(int i=1, p, l, r;i<=M;++i){
		p=lower_bound(A+1, A+N+1, Q[i])-A;
		if(p==1){
			Show_(A[p]-Q[i]);
		}
		else if(p==N+1){
			Show_(Q[i]-A[p-1]-1);
		}
		else{
			r=A[p]-Q[i];l=Q[i]-A[p-1]-1;
			if(l==r){
				Show__(l|r);
			}
			else if(min(l, r)==0)	Show(0.5*PI);
			else{
				double Max=0.0;
				Max=max(Max, Tag(min(l, r)));
				/*
				if(Fetch(Q[i]-r))	Max=max(Max, 2.0*Tag(r));
				if(Fetch(Q[i]+l))	Max=max(Max, 2.0*Tag(l));
				*/
				Da.move(Q[i]);//puts("!");
				Max=max(Da.val(), Max);
				Show(Max);
			}
		}
	}
	
	return 0;
}

/*
4 200
0 1 6 7
3
2 4 5

*/