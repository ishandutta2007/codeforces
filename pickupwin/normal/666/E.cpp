#include <iostream>
#include <string>

using namespace std;

const int MAXN=500111;
const int MAXM=50011;
const int MAXL=MAXN+(MAXM<<1);
const int MAXQ=500111;
const int MAXT=30000111;

string input;
int Data[MAXL], DL;
int Bel[MAXL], Pos[MAXL];
int M, Qcnt;

namespace Tree{
	
	struct Data{
		int v, id;
		void show(){
			cout << id << " " << v << "\n";
		}
	} Zero, Ans;
	
	Data operator + (Data A, Data B){
		Data ret;
		ret.v=max(A.v, B.v);
		if(B.v==ret.v)	ret.id=B.id;
		if(A.v==ret.v)	ret.id=A.id;
		return ret;
	}
	
	struct Node{
		int ls, rs;
		Data d;
	} T[MAXT];
	
	int Tcnt;
	
	void pup(int at){
		T[at].d=T[T[at].ls].d+T[T[at].rs].d;
	}
	
	void Merge(int &at, int a, int b, int l=1, int r=M){
		if(a>b)	swap(a, b);
		if(a==0)	{at=b;return;}
		++Tcnt;at=Tcnt;
		int m=(l+r)>>1;
		if(l==r)	{T[at].d.v=T[a].d.v+T[b].d.v;T[at].d.id=m;}
		else{
			Merge(T[at].ls, T[a].ls, T[b].ls, l, m);
			Merge(T[at].rs, T[a].rs, T[b].rs, m+1, r);
			pup(at);
		}
	}
	
	void Insert(int &at, int p, int l=1, int r=M){
		++Tcnt;T[Tcnt]=T[at];at=Tcnt;
		if(l==r)	{++T[at].d.v;T[at].d.id=p;return;}
		int m=(l+r)>>1;
		if(p>m)	Insert(T[at].rs, p, m+1, r);
		else	Insert(T[at].ls, p, l, m);
		pup(at);
	}
	
	Data Ask(int at, int ql, int qr, int l=1, int r=M){
		if(at<=0)	return Zero;
		if(l>=ql && r<=qr){
			return T[at].d;
		}
		int m=(l+r)>>1;
		Data ret=Zero;
		if(ql<=m)	ret=ret+Ask(T[at].ls, ql, qr, l, m);
		if(qr>m)	ret=ret+Ask(T[at].rs, ql, qr, m+1, r);
		return ret;
	}
	
	struct Vert{
		int Son, Bro;
		int Pre[21];
		int Len, Bel;
		int Root;
	} V[MAXL<<1];
	
	int Vcnt;
	
	void Link(int f, int i){
		if(f>0)	{V[i].Bro=V[f].Son;V[f].Son=i;}
		V[i].Pre[0]=f;
		//for(int j=1;j<21;++j)	V[i].Pre[j]=V[V[i].Pre[j-1]].Pre[j-1];
	}
	
	void DFS(int at){
		
		for(int to=V[at].Son;to>0;to=V[to].Bro){
			DFS(to);
			Merge(V[at].Root, V[at].Root, V[to].Root);
		}
		
		if(V[at].Bel>0)	Insert(V[at].Root, V[at].Bel);
		
	}
	
	int Find(int at, int l){
		//cout << at << " " << l << endl;
		for(int i=20;i>=0;--i)
			if(V[V[at].Pre[i]].Len>=l)
				at=V[at].Pre[i];
		return at;
	}
	
	/*
	void Show(){
		for(int i=1;i<=Vcnt;++i){
			cout << V[i].Pre[1] << " " << V[i].Pre[0] << " " << i << " " << V[i].Len << " " << V[i].Bel << "\n";
		}
	}
	*/
	
}

namespace Sam{
	
	struct Node{
		int Fa, Son[27];
		int Len;
	} T[MAXL<<1];
	
	int Tcnt, Root, Last;
	
	void Insert(int v){
		
		int np=++Tcnt, at=Last;Last=np;
		T[np].Len=T[at].Len+1;
		for(;at>0 && T[at].Son[v]<=0;at=T[at].Fa)	T[at].Son[v]=np;
		
		if(at<=0){
			T[np].Fa=Root;
			return;
		}
		
		int q=T[at].Son[v];
		if(T[q].Len==T[at].Len+1){
			T[np].Fa=q;
			return;
		}
		
		int nq=++Tcnt;T[nq]=T[q];
		T[nq].Len=T[at].Len+1;
		T[q].Fa=nq;T[np].Fa=nq;
		for(;at>0 && T[at].Son[v]==q;at=T[at].Fa)	T[at].Son[v]=nq;
		
	}
	
}

struct Seg{
	int l, r;
} Norm, S[MAXM];

struct Query{
	int pl, pr, l, r;
} Q[MAXQ];

int unCode(char c){
	return (c-'a');
}

void Push(string &str, Seg &s, int b=0){
	int l=str.length();
	s.l=DL+1;
	for(int i=0;i<l;++i){
		++DL;
		Data[DL]=unCode(input[i]);
		Bel[DL]=b;
	}
	s.r=DL;
}

void Read(){
	cin >> input;
	Push(input, Norm);
	Data[++DL]=26;
	cin >> M;
	for(int i=1;i<=M;++i){
		cin >> input;
		Push(input, S[i], i);
		Data[++DL]=26;
	}
	cin >> Qcnt;
	for(int i=1;i<=Qcnt;++i)
		cin >> Q[i].pl >> Q[i].pr >> Q[i].l >> Q[i].r;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	Read();
	
	{
		using namespace Sam;
		
		Root=++Tcnt;Last=Root;
		for(int i=1;i<=DL;++i)	{Insert(Data[i]);Pos[i]=Last;}
		
	}
	
	Tree::Vcnt=Sam::Tcnt;
	for(int i=1;i<=Tree::Vcnt;++i){
		Tree::Link(Sam::T[i].Fa, i);
		Tree::V[i].Len=Sam::T[i].Len;
	}
	
	{
		using namespace Tree;
		
		for(int j=1;j<21;++j)
			for(int i=1;i<=Vcnt;++i)
				V[i].Pre[j]=V[V[i].Pre[j-1]].Pre[j-1];
		
		for(int i=1;i<=DL;++i)	V[Pos[i]].Bel=Bel[i];
		
		//Show();
		
		DFS(1);
		
		for(int i=1, p;i<=Qcnt;++i){
			p=Find(Pos[Q[i].r], Q[i].r-Q[i].l+1);
			//cout << i << " " << p << endl;
			if(p<0)	cout << Q[i].pl << " 0\n";
			else{
				Ans=Ask(V[p].Root, Q[i].pl, Q[i].pr);
				if(Ans.v==0)	Ans.id=Q[i].pl;
				Ans.show();
			}
		}
		
	}
	
	return 0;
}

/*
ab
2
aaaaa
abab
2
1 2 1 1
1 2 1 2

1 5
2 2

*/

/*
suffixtree
2
ree
heee
1
1 2 9 10

2 2

*/