#include <cstdio>
#include <cassert>
#include <algorithm>
#include <set>

using std::set;
using std::swap;

const int MAXN=300011;

int N;
int P[MAXN];

bool In[MAXN];
set<int> Pos;

struct Opt{
	int a, b;
};

Opt O[MAXN<<3];
int Oc;

void Show(int l, int r){
	assert(((r-l)<<1)>=N);
	O[++Oc]=Opt{l, r};
}

void Swap(int a, int b){
	if(a>b)	swap(a, b);
	swap(P[a], P[b]);
	if(P[a]!=a)	Pos.insert(a);
	if(P[b]!=b)	Pos.insert(b);
	if(((b-a)<<1)>=N)	Show(a, b);
	else if(((a-1)<<1)>=N){
		Show(1, a);
		Show(1, b);
		Show(1, a);
	}
	else if(((N-b)<<1)>=N){
		Show(b, N);
		Show(a, N);
		Show(b, N);
	}
	else{
		Show(1, b);Show(a, N);
		Show(1, N);
		Show(1, b);Show(a, N);
	}
}

int main(){
	
	scanf("%d", &N);
	for(int i=1;i<=N;++i)	scanf("%d", &P[i]);
	
	for(int i=1;i<=N;++i)	Pos.insert(i);
	
	while(!Pos.empty()){
		int p=*Pos.begin();Pos.erase(p);
		if(P[p]!=p)	Swap(p, P[p]);
	}
	
	printf("%d\n", Oc);
	for(int i=1;i<=Oc;++i)	printf("%d %d\n", O[i].a, O[i].b);
	
	return 0;
}