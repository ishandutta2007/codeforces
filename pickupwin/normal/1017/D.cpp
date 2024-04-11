#include <cstdio>
#include <cstring>
#include <algorithm>

using std::sort;

const int MAXL=15;
const int MAXN=500111;
const int MAXM=500111;
const int MAXV=4333;

char input[MAXL];
int L, N, M, V;
int Val[MAXL];
int Num[MAXN];
int Cnt[MAXV];
int Ans[MAXV];

int unCode(){
	int ret=0;
	for(int i=1;i<=L;++i)
		ret=(ret<<1)+(input[i-1]-'0');
	return ret;
}

int CalcVal(int k){
	int ret=0;
	for(int i=L;i>=1;--i){
		if(k&1)	ret+=Val[i];
		k>>=1;
	}
	return ret;
}

struct Node{
	int v, Val;
} T[MAXV];

bool cmpv(Node A, Node B){
	return A.Val<B.Val;
}

struct Query{
	int v, p, id, ans;
} Q[MAXM];

bool cmpp(Query A, Query B){
	return A.p<B.p;
}

bool cmpid(Query A, Query B){
	return A.id<B.id;
}

int Find(int k){
	if(k<T[0].Val)	return -1;
	int Left=0, Right=V-1, Mid;
	while(Left<Right){
		Mid=(Left+Right)>>1;
		if(T[Mid+1].Val<=k)	Left=Mid+1;
		else	Right=Mid;
	}
	Mid=(Left+Right)>>1;
	return Mid;
}

int main(){
	
	scanf("%d%d%d", &L, &N, &M);
	for(int i=1;i<=L;++i)	scanf("%d", &Val[i]);
	for(int i=1;i<=N;++i){
		scanf("%s", input);
		Num[i]=unCode();
	}
	
	V=1<<L;
	
	for(int i=0;i<V;++i){
		T[i].Val=CalcVal(i);
		T[i].v=i;
	}
	
	sort(T, T+V, cmpv);
	
	//for(int i=0;i<V;++i)
	//	printf("%d %d\n", T[i].v, T[i].Val);
	
	for(int i=1;i<=N;++i)
		++Cnt[Num[i]];
	
	for(int i=1;i<=M;++i){
		scanf("%s", input);
		scanf("%d", &Q[i].p);
		Q[i].v=unCode();
		Q[i].p=Find(Q[i].p);
		Q[i].id=i;
	}
	
	//for(int i=1;i<=M;++i)
	//	printf("%d\n", Q[i].p);
	
	sort(Q+1, Q+M+1, cmpp);
	
	for(int i=0, k=1;i<V;++i){
		for(int j=0, vv;j<V;++j){
			vv=j^(V-1-T[i].v);
			Ans[j]+=Cnt[vv];
		}
		while(k<=M && Q[k].p<=i){
			if(Q[k].p==i)	Q[k].ans=Ans[Q[k].v];
			++k;
		}
	}
	
	sort(Q+1, Q+M+1, cmpid);
	
	for(int i=1;i<=M;++i)
		printf("%d\n", Q[i].ans);
	
	return 0;
}