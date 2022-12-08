#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>

using std::sort;
using std::queue;

const int INF=1034567890;

int N;
int Ans[2011];

char input[811];

struct Node{
	int s[10], f;
	int v[2011];
} V[63333];

int Tcnt, Root;

int L[811], Ll, R[811], Rl;

int Lim;

int Len, Val[811];

void Insert(int vp){
	int at=Root;
	for(int i=1, h;i<=Len;++i){
		h=Val[i];
		if(!V[at].s[h])	V[at].s[h]=++Tcnt;
		at=V[at].s[h];
	}
	if(vp<=N)	++V[at].v[vp];
}

void DFS(int p, bool l=true, bool r=true){
	if(p>Lim || (!l && !r)){
		Len=p-1;
		Insert(Lim-p+1);
		return;
	}
	for(int k=(l?L[p]:0);k<=(r?R[p]:9);++k){
		Val[p]=k;
		DFS(p+1, l && k==L[p], r && k==R[p]);
	}
}

void Fetch(int at){
	for(int i=0;i<=N;++i)	V[at].v[i]+=V[V[at].f].v[i];
}

queue<int> Q;

void Fall(int at=Root){
	V[at].f=0;
	Fetch(at);
	Q.push(at);
	while(!Q.empty()){
		at=Q.front();Q.pop();
		for(int i=0, to, f;i<10;++i){
			to=V[at].s[i];
			if(!to)	continue;
			for(f=V[at].f;f && !V[f].s[i];f=V[f].f);
			V[to].f=V[f].s[i];
			Fetch(to);
			Q.push(to);
		}
	}
}

void Shift(int at){
	for(int i=1;i<=N;++i)	V[at].v[i]+=V[at].v[i-1];
}

int Tra[63333][10];

int Tr(int p, int v){
	int &ret=Tra[p][v];
	if(!ret){
		while(!V[p].s[v])	p=V[p].f;
		ret=V[p].s[v];
	}
	return ret;
}

struct Data{
	int Val, Rk;
	Data(){}
	Data(int _v, int _r){Val=_v;Rk=_r;}
} BadData;

bool operator == (Data A, Data B){
	return A.Val==B.Val && A.Rk==B.Rk;
}

bool operator < (Data A, Data B){
	if(A.Val==B.Val)	return A.Rk>B.Rk;
	return A.Val<B.Val;
}

Data F[2][63333];
int Pre[2011][63333];

void relax(int l, Data d, int r, int v){
	int p=Tr(r, v);
	d.Val+=V[p].v[N-l];d.Rk*=10;d.Rk+=v;
	if(F[l&1][p]<d)	{Pre[l][p]=r*10+v;F[l&1][p]=d;}
}

struct Pair{
	int v, *p;
	Pair(){}
	Pair(int _v, int *_p){v=_v;p=_p;}
} P[63333];

bool operator < (Pair A, Pair B){
	return A.v<B.v;
}

int Pc;

void Shake(int t){
	Pc=0;
	for(int i=1;i<=Tcnt;++i){
		if(F[t][i]==BadData)	continue;
		P[++Pc]=Pair(F[t][i].Rk, &F[t][i].Rk);
	}
	sort(P+1, P+Pc+1);
	for(int i=1;i<=Pc;++i)	(*P[i].p)=i;
}

int main(){
	
	BadData.Val=-INF;
	
	scanf("%s", input);
	Ll=strlen(input);
	for(int i=1;i<=Ll;++i)	L[i]=input[i-1]-'0';
	
	scanf("%s", input);
	Rl=strlen(input);
	for(int i=1;i<=Rl;++i)	R[i]=input[i-1]-'0';
	
	scanf("%d", &N);
	
	Root=++Tcnt;
	for(int i=0;i<10;++i)	V[0].s[i]=Root;
	
	if(Ll==Rl){
		Lim=Ll|Rl;
		DFS(1);
	}
	else{
		for(int l=Rl-2;l>=Ll;--l)
			for(int i=1;i<=9;++i){
				Len=1;Val[1]=i;
				Insert(l);
			}
		for(int i=1;i<=Ll;++i){
			for(int k=L[i]+1;k<=9;++k){
				Len=i;
				for(int j=1;j<i;++j)
					Val[j]=L[j];
				Val[i]=k;
				Insert(Ll-i);
			}
		}
		Len=Ll;for(int j=1;j<=Len;++j)	Val[j]=L[j];Insert(0);
		for(int i=1;i<=Rl;++i){
			for(int k=(i==1);k<R[i];++k){
				Len=i;
				for(int j=1;j<i;++j)
					Val[j]=R[j];
				Val[i]=k;
				Insert(Rl-i);
			}
		}
		Len=Rl;for(int j=1;j<=Len;++j)	Val[j]=R[j];Insert(0);
	}
	
	Fall();
	
	for(int i=1;i<=Tcnt;++i)	Shift(i);
	
	/*
	printf("%d\n", Tcnt);
	for(int i=0;i<=Tcnt;++i, puts("")){
		printf("%d: ", i);
		for(int j=0;j<10;++j)	printf("%d->%d ", j, V[i].s[j]);
		for(int j=0;j<=N;++j)	printf("v[%d]=%d ", j, V[i].v[j]);
		printf("f->%d", V[i].f);
	}
	*/
	
	for(int i=1;i<=Tcnt;++i)	F[0][i]=BadData;
	F[0][Root]=Data(0, 1);
	
	for(int i=1, p=0, t=1;i<=N;++i, p^=1, t^=1){
		for(int j=1;j<=Tcnt;++j){
			F[t][j]=BadData;
		}
		for(int j=1;j<=Tcnt;++j){
			if(F[p][j]==BadData)	continue;
			for(int v=0;v<=9;++v){
				relax(i, F[p][j], j, v);
			}
		}
		Shake(t);
	}
	
	int Ap=1;
	for(int i=2;i<=Tcnt;++i)	if(F[N&1][Ap]<F[N&1][i])	Ap=i;
	
	
	printf("%d\n", F[N&1][Ap].Val);
	for(int i=N;i>=1;--i){
		Ans[i]=Pre[i][Ap]%10;
		Ap=Pre[i][Ap]/10;
	}
	for(int i=1;i<=N;++i)	printf("%d", Ans[i]);
	puts("");
	
	return 0;
}