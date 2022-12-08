#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN=100111;
const int MAXM=1000011;

long long Out[MAXM];

int N, M;

struct Data{
	long long a, b;
	Data(){}
	Data(long long _a, long long _b){
		a=_a;b=_b;
	}
	void read(){
		cin >> a >> b;
	}
	long long v(int k){
		return a*k+b;
	}
} Zero, D__;

bool cmpab(Data A, Data B){
	if(A.a==B.a)	return A.b>B.b;
	return A.a<B.a;
}

Data operator + (Data A, Data B){
	return Data(A.a+B.a, A.b+B.b);
}

Data operator - (Data A, Data B){
	return Data(A.a-B.a, A.b-B.b);
}

long double operator * (Data A, Data B){
	return 1.0L*A.a*B.b-1.0L*A.b*B.a;
}

struct Vert{
	int FE;
	int Size, Val;
};

struct Edge{
	int x, y, next;
	Data d;
};

typedef vector<Data> Poly;

Poly P__;
void Norm(Poly &P){
	sort(P.begin(), P.end(), cmpab);
	#define End P__[c-1]
	#define Pre P__[c-2]
	#define New P[i]
	for(int i=0, s=P.size(), c;i<s;++i){
		if(i && P[i].a==P[i-1].a)	continue;
		c=P__.size();
		while(c>1 && (End-Pre)*(New-End)>=0.0L){
			P__.pop_back();
			c=P__.size();
		}
		P__.push_back(New);
	}
	#undef End
	#undef Pre
	#undef New
	P=P__;P__.clear();
}

Poly operator + (Poly A, Poly B){
	Poly ret;
	for(int a=0, s=A.size();a<s;++a)	ret.push_back(A[a]);
	for(int b=0, s=B.size();b<s;++b)	ret.push_back(B[b]);
	return ret;
}

inline void operator += (Poly &A, Data d){
	A.push_back(d);
}

Poly Left, Right;
void Merge(Poly &P){
	#define L Left
	#define R Right
	int ls=L.size(), rs=R.size();
	--ls;--rs;
	int l=0, r=0;
	while(l<ls || r<rs){
		P+=(L[l]+R[r]);
		if(r==rs || (l<ls && (R[r+1]-R[r])*(L[l+1]-L[l])>=0.0L))
			++l;
		else	++r;
	}
	P+=(L[l]+R[r]);
	#undef L
	#undef R
	Norm(P);
	Left.clear();Right.clear();
}

namespace Tree{
	Vert V[MAXN<<1];
	int Vcnt;
	Edge E[MAXN<<2];
	int Ecnt;
	
	bool Vis[MAXN<<2];
	
	inline int ed(int a){
		return (a+1)>>1;
	}
	
	void addE(int a, int b, Data d){
		++Ecnt;
		E[Ecnt].x=a;E[Ecnt].y=b;E[Ecnt].next=V[a].FE;V[a].FE=Ecnt;
		E[Ecnt].d=d;
	}
	
	void Show(){
		cout << Vcnt << endl;
		for(int i=1;i<=Ecnt;i+=2)
			cout << E[i].x << " " << E[i].y << " " << E[i].d.a << " " << E[i].d.b << endl;
	}
	
	int AllSize;
	
	void getSize(int at, int f){
		V[at].Size=1;
		for(int k=V[at].FE, to;k;k=E[k].next){
			if(Vis[ed(k)])	continue;
			to=E[k].y;
			if(to==f)	continue;
			getSize(to, at);
			V[at].Size+=V[to].Size;
		}
	}
	
	void getVal(int at, int f){
		V[at].Val=max(V[at].Size, AllSize-V[at].Size);
		for(int k=V[at].FE, to;k;k=E[k].next){
			if(Vis[ed(k)])	continue;
			to=E[k].y;
			if(to==f)	continue;
			getVal(to, at);
		}
	}
	
	int GE, GVal;
	
	void getG(int at, int e){
		if(V[at].Val<GVal){
			GE=e;GVal=V[at].Val;
		}
		for(int k=V[at].FE, to;k;k=E[k].next){
			if(Vis[ed(k)] || ed(k)==ed(e))	continue;
			to=E[k].y;
			getG(to, k);
		}
	}
	
	void Search(int at, int f, Data t, Poly &P){
		int sc=0;
		for(int k=V[at].FE, to;k;k=E[k].next){
			if(Vis[ed(k)])	continue;
			to=E[k].y;
			if(to==f)	continue;
			Search(to, at, t+E[k].d, P);
			++sc;
		}
		if(!sc)	P+=t;
	}
	
	Poly Calc(int at){//cout << at << "? ";
		Poly ret;
		getSize(at, 0);AllSize=V[at].Size;
		if(AllSize==1)	return ret;
		getVal(at, 0);
		GE=0;GVal=AllSize;
		getG(at, 0);
		int e=GE;//cout << "!" << e << " " << E[e].x << " " << E[e].y << " " << E[e].d.a << " " << E[e].d.b << endl;
		Vis[ed(e)]=true;
		Search(E[e].x, 0, Zero, Left);Norm(Left);
		Search(E[e].y, 0, Zero, Right);Norm(Right);
		/*
		cout << "L-----" << endl;
		for(int i=0, s=Left.size();i<s;++i){
			cout << Left[i].a << " " << Left[i].b << endl;
		}
		cout << "R-----" << endl;
		for(int i=0, s=Right.size();i<s;++i){
			cout << Right[i].a << " " << Right[i].b << endl;
		}
		*/
		Merge(ret);
		for(int i=0, s=ret.size();i<s;++i)	ret[i]=ret[i]+E[e].d;
		/*
		for(int i=0, s=ret.size();i<s;++i){
			cout << ret[i].a << " " << ret[i].b << endl;
		}
		cout << "--------------------------------" << endl;
		cout << E[e].x << " " << E[e].y << endl;
		*/
		ret=ret+Calc(E[e].x);
		ret=ret+Calc(E[e].y);
		Norm(ret);
		return ret;
	}
	
}

namespace Map{
	Vert V[MAXN];
	int Vcnt;
	Edge E[MAXN<<1];
	int Ecnt;
	
	void addE(int a, int b, Data d){
		++Ecnt;
		E[Ecnt].x=a;E[Ecnt].y=b;E[Ecnt].next=V[a].FE;V[a].FE=Ecnt;
		E[Ecnt].d=d;
	}
	
}

int Three(int at, int f){
	using Tree::Vcnt;
	using Map::V;
	using Map::E;
	using Tree::addE;
	int Id=++Vcnt;
	int P=Id, S;
	for(int k=V[at].FE, to;k;k=E[k].next){
		to=E[k].y;
		if(to==f)	continue;
		++Vcnt;
		addE(P, Vcnt, Zero);
		addE(Vcnt, P, Zero);
		P=Vcnt;
		S=Three(to, at);
		addE(P, S, E[k].d);
		addE(S, P, E[k].d);
	}
	return Id;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M;
	
	{
		using namespace Map;
		
		for(int i=1, a, b;i<N;++i){
			cin >> a >> b;
			D__.read();
			addE(a, b, D__);addE(b, a, D__);
		}
		
	}
	
	Three(1, 0);
	
	//Tree::Show();
	
	Poly Ans=Tree::Calc(1);
	
	/*
	for(int i=0, s=Ans.size();i<s;++i){
		cout << Ans[i].a << " " << Ans[i].b << endl;
	}
	*/
	
	if(Ans.empty()){
		for(int i=0;i<M;++i)	cout << "0 ";
		cout << endl;
		return 0;
	}
	
	for(int i=0, p=0, s=Ans.size()-1;i<M;++i){
		while(p<s && Ans[p+1].v(i)>Ans[p].v(i))	++p;
		Out[i]=Ans[p].v(i);
	}
	
	for(int i=0;i<M;++i)	cout << Out[i] << " ";
	cout << endl;
	
	return 0;
}

/*
17 19
2 16 0 0
17 7 0 0
14 1 0 0
17 3 1 999999999
2 17 0 0
7 15 0 1000000000
7 1 0 0
10 16 0 0
14 9 4 999999990
14 5 0 0
5 4 0 0
10 8 6 999999979
5 12 7 999999972
6 2 2 999999997
16 11 3 999999994
13 1 5 999999985

*/