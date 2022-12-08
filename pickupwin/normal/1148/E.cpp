#include <cstdio>
#include <set>
#include <cstdlib>
#include <algorithm>

using std::sort;
using std::min;
using std::set;

const int MAXN=300011;

struct Opt{
	int l, r, d;
};

Opt O[MAXN<<3];
int Oc;

void Show(int _l, int _r, int _d){
	if(_d==0)	return;
	O[++Oc]=Opt{_l, _r, _d};
}

struct Pair{
	int id, s;
};

inline bool operator < (const Pair &A, const Pair &B){
	return (A.s==B.s)?A.id<B.id:A.s<B.s;
}

set<Pair> Set;

int N;
int S[MAXN], T[MAXN];

void Move(Pair &A, Pair &B, int aim){
	int d=min(aim-A.s, B.s-aim);
	Show(A.id, B.id, d);
	A.s+=d;B.s-=d;
}

void Fail(bool i){
	if(i){puts("NO");
	exit(0);}
}

int main(){
	
	scanf("%d", &N);
	for(int i=1;i<=N;++i)	scanf("%d", &S[i]);
	for(int i=1;i<=N;++i)	Set.insert(Pair{i, S[i]});
	for(int i=1;i<=N;++i)	scanf("%d", &T[i]);
	sort(T+1, T+N+1);
	
	for(int i=1, v;i<N;++i){
		Pair P=*Set.begin();
		Set.erase(P);
		v=P.s;
		Fail(v>T[i]);
		if(v!=T[i]){
			Pair Q=*Set.lower_bound(Pair{0, T[i]});
			Set.erase(Q);
			Move(P, Q, T[i]);
			if(P.s==T[i])
				Set.insert(Q);
			else Set.insert(P);
		}
	}
	Fail((*Set.begin()).s!=T[N]);
	
	puts("YES");
	printf("%d\n", Oc);
	for(int i=1;i<=Oc;++i)	printf("%d %d %d\n", O[i].l, O[i].r, O[i].d);
	
	return 0;
	
}