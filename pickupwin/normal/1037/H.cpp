#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAXL=200111;

char enCode(int a){
	return (char)('a'+a);
}

string input;

int A[MAXL], Al;
int Id[MAXL];

int M;
int L, R;
int Q[MAXL], Ql;

namespace Sam{
	
	struct Node{
		int s[26], f;
		int l;
	} T[MAXL<<1];
	
	int Tcnt, Root, Last;
	
	void Insert(int v){
		
		int np=++Tcnt, at=Last;Last=np;
		T[np].l=T[at].l+1;
		for(;at && !T[at].s[v];at=T[at].f)	T[at].s[v]=np;
		
		if(!at){
			T[np].f=Root;
			return;
		}
		
		int q=T[at].s[v];
		if(T[q].l==T[at].l+1){
			T[np].f=q;
			return;
		}
		
		int nq=++Tcnt;T[nq]=T[q];
		T[nq].l=T[at].l+1;
		T[q].f=nq;T[np].f=nq;
		for(;at && T[at].s[v]==q;at=T[at].f)	T[at].s[v]=nq;
		
	}
	
	struct Vert{
		int Son, Bro;
		int Dps, Dpr;
	} V[MAXL<<1];
	
	void Link(int a, int b){
		//cout << a << " " << b << endl;
		V[b].Bro=V[a].Son;
		V[a].Son=b;
	}
	
	int DFN;
	
	void DFS(int at=Root){
		++DFN;
		V[at].Dps=DFN;
		for(int to=V[at].Son;to;to=V[to].Bro){
			DFS(to);
		}
		V[at].Dpr=DFN;
	}
	
}

namespace Chair{
	
	struct Node{
		int ls, rs;
		int cnt;
	} T[MAXL*19];
	
	int Tcnt, Root[MAXL<<1], Rc;
	
	void Update(int &at, int p, int l, int r){
		++Tcnt;T[Tcnt]=T[at];at=Tcnt;
		++T[at].cnt;
		if(l==r)	return;
		int m=(l+r)>>1;
		if(p>m)	Update(T[at].rs, p, m+1, r);
		else	Update(T[at].ls, p, l, m);
	}
	
	int Query(int at, int ql, int qr, int l, int r){
		if(l>=ql && r<=qr)	return T[at].cnt;
		int m=(l+r)>>1, ret=0;
		if(ql<=m)	ret+=Query(T[at].ls, ql, qr, l, m);
		if(qr>m)	ret+=Query(T[at].rs, ql, qr, m+1, r);
		return ret;
	}
	
	struct Data{
		int dps, pos;
	} D[MAXL];
	
	bool cmpdps(Data A, Data B){
		return A.dps<B.dps;
	}
	
	int Dc;
	
	void addD(int a, int b){
		//cout << "Data " << a << " " << b << endl;
		++Dc;
		D[Dc].dps=a;D[Dc].pos=b;
	}
	
	void Calc(){
		sort(D+1, D+Dc+1, cmpdps);
		
		int j=0;
		for(int i=1;i<=Dc;++i){
			while(j<Rc && j<D[i].dps){
				++j;Root[j]=Root[j-1];
			}
			Update(Root[j], D[i].pos, 1, Al);
		}
		
	}
	
	bool Query(int rl, int rr, int pl, int pr){
		//cout << rl << " " << rr << " " << pl << " " << pr << endl;
		return Query(Root[rr], pl, pr, 1, Al)>Query(Root[rl-1], pl, pr, 1, Al);
	}
	
	int Find(int rl, int rr, int pl, int pr){
		int pm;
		while(pl<pr){
			pm=(pl+pr)>>1;
			if(Query(rl, rr, pl, pm))	pr=pm;
			else	pl=pm+1;
		}
		pm=(pl+pr)>>1;
		return pm;
	}
	
}

int Ansl, Ansr;

bool Ask(int at, int l, int r){
	int rl=Sam::V[at].Dps, rr=Sam::V[at].Dpr;
	//cout << "Ask " << at << " " << l << " " << r << endl;
	if(Chair::Query(rl, rr, l, r)){
		Ansr=Chair::Find(rl, rr, l, r);
		Ansl=Ansr-(l-L);
		return true;
	}
	return false;
}

bool Search(int at, int p){//cout << "Search " << at << " " << p << endl;
	using Sam::T;
	if(p<=Ql && T[at].s[Q[p]] && Search(T[at].s[Q[p]], p+1))	return true;
	if(L+p-1>R)	return false;
	bool ret=false;
	for(int c=Q[p]+1;c<26 && !ret;++c){
		if(!T[at].s[c])	continue;
		ret|=Ask(T[at].s[c], L+p-1, R);
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> input;
	
	Al=input.length();
	for(int i=1;i<=Al;++i)	A[i]=input[i-1]-'a';
	
	{
		using namespace Sam;
		Last=Root=++Tcnt;
		for(int i=1;i<=Al;++i)	{Id[i]=Tcnt+1;Insert(A[i]);}
		
		for(int i=1;i<=Tcnt;++i)	if(T[i].f)	Link(T[i].f, i);
		
		DFS();
		
	}
	
	for(int i=1;i<=Al;++i)	Chair::addD(Sam::V[Id[i]].Dps, i);
	
	Chair::Rc=Sam::Tcnt;
	
	Chair::Calc();
	
	cin >> M;
	
	while(M--){
		
		cin >> L >> R >> input;
		
		Ql=input.length();
		for(int i=1;i<=Ql;++i)	Q[i]=input[i-1]-'a';
		Q[Ql+1]=-1;
		
		Ansl=Ansr=0;
		Search(Sam::Root, 1);
		
		if(Ansl>Ansr || Ansl<1 || Ansr>Al)	cout << "-1" << endl;
		else{
			for(int i=Ansl;i<=Ansr;++i)	cout << enCode(A[i]);
			cout << endl;
		}
	}
	
	return 0;
}