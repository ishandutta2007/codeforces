#include <cstdio>
#include <algorithm>
#include <cassert>

using std::sort;
using std::swap;

const int MAXN=300011;

int N;

struct Pair{
	int a, b;
} P[MAXN];

int Cnt[2];

int Rk[MAXN], Rc;

inline bool cmpa(const int &a, const int &b){
	return P[a].a<P[b].a;
}

int main(){
	
	
	scanf("%d", &N);
	
	for(int i=1;i<=N;++i){
		scanf("%d%d", &P[i].a, &P[i].b);
	}
	
	for(int i=1;i<=N;++i)	++Cnt[P[i].a<P[i].b];
	
	if(Cnt[1]>Cnt[0]){
		for(int i=1;i<=N;++i)	if(P[i].a<P[i].b)	Rk[++Rc]=i;
		sort(Rk+1, Rk+Rc+1, cmpa);
		assert(Cnt[1]==Rc);
		
	}
	else{
		for(int i=1;i<=N;++i)	if(P[i].a>P[i].b)	Rk[++Rc]=i;
		sort(Rk+1, Rk+Rc+1, cmpa);
		assert(Cnt[0]==Rc);
		for(int i=1, j=Rc;i<j;++i, --j)	swap(Rk[i], Rk[j]);
	}
	
	printf("%d\n", Rc);
	for(int i=Rc;i>=1;--i)	printf("%d ", Rk[i]);
	puts("");
	
	return 0;
}