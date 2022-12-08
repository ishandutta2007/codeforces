#include <cstdio>
#include <algorithm>

using std::sort;

const int MAXN=100011;

int N;

struct Pos{
	long long x, y;
} P[MAXN];

Pos U[MAXN];
int Uc;

inline bool cmpxy(const Pos &A, const Pos &B){
	return (A.x==B.x)?A.y<B.y:A.x<B.x;
}

inline Pos operator - (const Pos &A, const Pos &B){
	return (Pos){A.x-B.x, A.y-B.y};
}

inline long long operator * (const Pos &A, const Pos &B){
	return A.x*B.y-A.y*B.x;
}

int main(){
	
	
	scanf("%d", &N);
	
	for(int i=1;i<=N;++i)
		scanf("%I64d%I64d", &P[i].x, &P[i].y);
	
	for(int i=1;i<=N;++i)	P[i].y-=P[i].x*P[i].x;
	
	sort(P+1, P+N+1, cmpxy);
	
	for(int i=1;i<=N;++i){
		while(Uc>1 && (U[Uc]-U[Uc-1])*(P[i]-U[Uc])>=0LL)	--Uc;
		U[++Uc]=P[i];
	}
	
	int Ans=0;
	for(int i=1;i<Uc;++i)	Ans+=U[i].x!=U[i+1].x;
	printf("%d\n", Ans);
	
	return 0;
}