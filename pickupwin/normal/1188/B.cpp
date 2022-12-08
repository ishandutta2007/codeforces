#include <cstdio>
#include <map>

using std::map;

map<int, int> Map;

const int MAXN=300011;

int N, P, K;

inline int sum(const int &a, const int &b){
	return (a+b>=P)?(a+b-P):(a+b);
}

inline int mul(const int &a, const int &b){
	return (int)((1LL*a*b)%(long long)(P));
}

int pow(int a, int k){
	int r=1;
	while(k){
		if(k&1)	r=mul(r, a);
		a=mul(a, a);
		k>>=1;
	}
	return r;
}

int A[MAXN];

inline int Val(const int &a){
	return sum(pow(a, 4), P-mul(K, a));
}

int main(){
	
	scanf("%d%d%d", &N, &P, &K);
	for(int i=1;i<=N;++i)	scanf("%d", &A[i]);
	
	long long Ans=0LL;
	for(int i=1;i<=N;++i){
		Ans+=Map[Val(A[i])];
		++Map[Val(A[i])];
	}
	printf("%I64d\n", Ans);
	
	return 0;
}