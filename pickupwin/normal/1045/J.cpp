#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

const ull BASE=29ULL;
const int MAXL=111;
const int MAXN=100011;

int unCode(char c){
	return c-'a';
}

string com;
int N, M;
ull Pow[MAXL];

struct Hash_Pair{
	ull h;
	int l;
	Hash_Pair(){}
	Hash_Pair(ull _h, int _l){h=_h;l=_l;}
};

bool operator == (Hash_Pair A, Hash_Pair B){
	return A.h==B.h && A.l==B.l;
}

namespace Chair{
	
	struct Node{
		int ls, rs;
		int d;
	} T[MAXN*73];
	
	int Tcnt, Root[MAXN<<1], Rc;
	
	void Update(int &at, int ql, int qr, int l, int r){
		++Tcnt;T[Tcnt]=T[at];at=Tcnt;
		if(ql<=l && r<=qr)	{++T[at].d;return;}
		int m=(l+r)>>1;
		if(ql<=m)	Update(T[at].ls, ql, qr, l, m);
		if(qr>m)	Update(T[at].rs, ql, qr, m+1, r);
	}
	
	int Ask(int at, int p, int l, int r){
		int ret=T[at].d;
		if(l==r)	return ret;
		int m=(l+r)>>1;
		if(p>m)	ret+=Ask(T[at].rs, p, m+1, r);
		else	ret+=Ask(T[at].ls, p, l, m);
		return ret;
	}
	
	struct Data{
		int p, l, r;
	} D[MAXN];
	
	bool operator < (Data A, Data B){
		return A.p<B.p;
	}
	
	int Dc;
	
	void addD(int p, int l, int r){
		//cout << "Data " << p << " " << l << " " << r << endl;
		++Dc;
		D[Dc].p=p;D[Dc].l=l;D[Dc].r=r;
	}
	
	void Calc(){
		
		sort(D+1, D+Dc+1);
		
		int j=0;
		for(int i=1;i<=Dc;++i){
			while(j<Rc && j<D[i].p){
				++j;Root[j]=Root[j-1];
			}
			Update(Root[j], D[i].l, D[i].r, 1, N);
		}
		
	}
	
	int Query(int p, int l, int r){
		return Ask(Root[r], p, 1, N)-Ask(Root[l-1], p, 1, N);
	}
	
}

namespace Sam{
	
	struct Vert{
		int Son, Bro;
		int Dps, Dpr;
	} V[MAXN<<1];
	
	void Link(int a, int b){
		V[b].Bro=V[a].Son;
		V[a].Son=b;
	}
	
	int DFN;
	
	void Search(int at){
		++DFN;
		V[at].Dps=DFN;
		for(int to=V[at].Son;to;to=V[to].Bro)
			Search(to);
		V[at].Dpr=DFN;
	}
	
	struct Node{
		int s[26], f;
		int Len;
		//int dps, dpr;
	} T[MAXN<<1];
	
	int Tcnt, Root;
	
	int Insert(int v, int at){
		
		if(T[at].s[v]){
			int q=T[at].s[v];
			if(T[q].Len==T[at].Len+1)	return q;
			int nq=++Tcnt;T[nq]=T[q];
			T[nq].Len=T[at].Len+1;
			T[q].f=nq;
			for(;at && T[at].s[v]==q;at=T[at].f)	T[at].s[v]=nq;
			return nq;
		}
		
		int np=++Tcnt;
		T[np].Len=T[at].Len+1;
		for(;at && !T[at].s[v];at=T[at].f)	T[at].s[v]=np;
		
		if(!at){
			T[np].f=Root;
			return np;
		}
		
		int q=T[at].s[v];
		if(T[q].Len==T[at].Len+1){
			T[np].f=q;
			return np;
		}
		
		int nq=++Tcnt;T[nq]=T[q];
		T[nq].Len=T[at].Len+1;
		T[np].f=nq;T[q].f=nq;
		for(;at && T[at].s[v]==q;at=T[at].f)	T[at].s[v]=nq;
		return np;
		
	}
	
	void Search(){
		for(int i=1;i<=Tcnt;++i)	if(T[i].f)	Link(T[i].f, i);
		Search(Root);
	}
	
	//int dfn;
	
	/*
	void Search(int at=Root){
		++dfn;
		T[at].dps=dfn;
		for(int i=0;i<26;++i){
			if(T[at].s[i]){
				//cout << "(" << T[at].s[i] << " " << at << ")" << endl;
				Search(T[at].s[i]);
			}
		}
		T[at].dpr=dfn;
	}
	*/
	
}

namespace Tree{
	
	struct Vert{
		int FE;
		int Dep, Pre[18];
		int Dps, Dpr;
		int Id;
		ull Hash;
	} V[MAXN];
	
	struct Edge{
		int y, l, next;
	} E[MAXN<<1];
	
	int Ecnt;
	
	void addE(int a, int b, int c){
		++Ecnt;
		E[Ecnt].y=b;E[Ecnt].l=c;E[Ecnt].next=V[a].FE;V[a].FE=Ecnt;
	}
	
	int Dfn[MAXN], DFN;
	
	void DFS(int at){
		Dfn[++DFN]=at;
		V[at].Dps=DFN;
		for(int k=V[at].FE, to;k>0;k=E[k].next){
			to=E[k].y;
			if(to==V[at].Pre[0])	continue;
			V[to].Dep=V[at].Dep+1;
			V[to].Pre[0]=at;
			V[to].Id=Sam::Insert(E[k].l, V[at].Id);
			V[to].Hash=V[at].Hash*BASE+(ull)(E[k].l);
			DFS(to);
		}
		V[at].Dpr=DFN;
	}
	
	int LCA(int a, int b){
		if(V[a].Dep<V[b].Dep)	swap(a, b);
		for(int i=17;i>=0;--i)
			if(V[V[a].Pre[i]].Dep>=V[b].Dep)
				a=V[a].Pre[i];
		if(a!=b){
			for(int i=17;i>=0;--i)
				if(V[a].Pre[i]!=V[b].Pre[i]){
					a=V[a].Pre[i];
					b=V[b].Pre[i];
				}
			a=V[a].Pre[0];
			b=V[b].Pre[0];
		}
		return (a+b)>>1;
	}
	
	void Jump(int &at, int dep){
		for(int i=17;i>=0;--i)
			if(V[V[at].Pre[i]].Dep>=dep)	at=V[at].Pre[i];
	}
	
	Hash_Pair Hash(int a, int f){
		int l=V[a].Dep-V[f].Dep;
		ull h=V[a].Hash-V[f].Hash*Pow[l];
		return Hash_Pair(h, l);
	}
	
}

namespace Str{
	
	int L;
	int Num[MAXL];
	ull Hash[MAXL];
	
	void Calc_Hash(){
		Hash[0]=0ULL;
		for(int i=1;i<=L;++i)	Hash[i]=Hash[i-1]*BASE+(ull)(Num[i]);
	}
	
	void Push(string s){
		L=s.length();
		for(int i=1;i<=L;++i)	Num[i]=unCode(s[i-1]);
		Calc_Hash();
	}
	
	void Rev(){
		for(int i=1, j=L;i<j;++i, --j)	swap(Num[i], Num[j]);
		Calc_Hash();
	}
	
	Hash_Pair H(int l, int r){
		int len=(r-l+1);
		ull h=Hash[r]-Hash[l-1]*Pow[len];
		return Hash_Pair(h, len);
	}
	
	int Calc(int a, int f){//cout << "Calc " << a << " " << f << endl;
		int p=Sam::Root;
		for(int i=1, h;i<=L;++i){h=Num[i];
			if(!Sam::T[p].s[h])	return 0;
			p=Sam::T[p].s[h];
		}
		int ret=Chair::Query(Tree::V[a].Dps, Sam::V[p].Dps, Sam::V[p].Dpr);
		ret-=Chair::Query(Tree::V[f].Dps, Sam::V[p].Dps, Sam::V[p].Dpr);
		//cout << "---------" << endl;
		return ret;
	}
	
}

bool Lm[MAXL], Rm[MAXL];

void Deal(int &a, int &b, string &s){
	int ret=0;
	int strl=s.length();
	for(int i=1;i<=strl;++i){
		Lm[i]=Rm[i]=false;
	}
	int c=Tree::LCA(a, b);
	//cout << a << " " << b << " " << c << endl;
	int ta=a, tb=b;
	Hash_Pair Tr, St;
	Str::Push(s);
	using Tree::V;
	using Tree::Jump;
	using Tree::Hash;
	using Str::H;
	if(V[b].Dep-V[c].Dep>=strl){
		Jump(b, V[c].Dep+strl);
		b=V[b].Pre[0];
		ret+=Str::Calc(tb, b);
	}
	for(;b!=c;b=V[b].Pre[0]){//cout << b << " " << c << endl;
		Tr=Hash(b, c);
		St=H(strl-Tr.l+1, strl);
		//cout << Tr.h << " " << Tr.l << " " << St.h << " " << St.l << endl;
		if(Tr==St)	Rm[Tr.l]=true;
	}
	Str::Rev();
	if(V[a].Dep-V[c].Dep>=strl){
		Jump(a, V[c].Dep+strl);
		a=V[a].Pre[0];
		ret+=Str::Calc(ta, a);
	}
	for(;a!=c;a=V[a].Pre[0]){//cout << a << " " << c << endl;
		Tr=Hash(a, c);
		St=H(strl-Tr.l+1, strl);
		if(Tr==St)	Lm[Tr.l]=true;
	}
	for(int i=1;i<strl;++i)	if(Lm[i] && Rm[strl-i])	++ret;
	cout << ret << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	Pow[0]=1ULL;
	for(int i=1;i<MAXL;++i)	Pow[i]=Pow[i-1]*BASE;
	
	cin >> N;
	
	{
		
		using Tree::addE;
		
		for(int i=1, a, b, c;i<N;++i){
			cin >> a >> b;
			cin >> com;
			c=unCode(com[0]);
			addE(a, b, c);addE(b, a, c);
		}
		
		using Sam::Tcnt;
		using Sam::Root;
		
		Root=++Tcnt;
		
		using Tree::V;
		
		V[1].Dep=1;V[1].Id=Root;
		Tree::DFS(1);
		
		for(int j=1;j<18;++j)
			for(int i=1;i<=N;++i)
				V[i].Pre[j]=V[V[i].Pre[j-1]].Pre[j-1];
		
		Sam::Search();
		
		for(int i=1, p;i<=N;++i){
			p=Sam::V[V[i].Id].Dps;
			Chair::addD(p, V[i].Dps, V[i].Dpr);
		}
		
		Chair::Rc=Sam::Tcnt;
		
		Chair::Calc();
		
		cin >> M;
		
		int X, Y;
		
		while(M--){
			cin >> X >> Y >> com;
			Deal(X, Y, com);
		}
		
	}
	
	return 0;
}

/*
6
2 3 g
3 4 n
5 3 o
6 1 n
1 2 d
9
1 6 n
6 4 dg
6 4 n
2 5 og
1 2 d
6 5 go
2 3 g
6 4 ndg
4 6 ngd

*/