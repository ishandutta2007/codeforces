#include <iostream>
#include <set>
//#include <fstream>

using namespace std;

//ifstream cin("CF603E.txt", ios_base::in);

const int INF=1034567890;
const int MAXN=111111;
const int MAXM=333333;

int N, M;
int oddBlockCnt;
set< pair<int, int> > st;

struct Node{
	int Val, Size, ISize, MaxV, MVat, Id;
	int r;
	Node *s[2], *f;
	
	Node(bool i=false);
	
	void sc(Node *x, int d){(s[d]=x)->f=this;}
	int d(){return f->s[1]==this;}
	bool rt(){return f->s[0]!=this && f->s[1]!=this;}
	
	void pup(){
		Size=s[0]->Size+s[1]->Size+ISize+1;
		MaxV=Val;
		MaxV=max(MaxV, s[0]->MaxV);
		MaxV=max(MaxV, s[1]->MaxV);
		if(MaxV==Val)	MVat=Id;
		if(MaxV==s[0]->MaxV)	MVat=s[0]->MVat;
		if(MaxV==s[1]->MaxV)	MVat=s[1]->MVat;
	}
	
	void mr(){
		r^=1;
		swap(s[0], s[1]);
	}
	
	void pdw(){
		if(r!=0){
			s[0]->mr();
			s[1]->mr();
			r=0;
		}
	}
	
} *NIL=new Node(true), *T[MAXN+MAXM];

Node::Node(bool i){
	if(i){s[0]=NULL;s[1]=NULL;f=NULL;}
	else{s[0]=NIL;s[1]=NIL;f=NIL;}
	Val=-INF;Size=0;ISize=0;MaxV=0;MVat=-1;Id=-1;
}

void zig(Node *x){
	int d=x->d();
	Node *y=x->f;
	y->sc(x->s[!d], d);
	if(!y->rt())	y->f->sc(x, y->d());
	else	x->f=y->f;
	x->sc(y, !d);
	y->pup();x->pup();
}

void splay(Node *x){
	for(Node *y;!x->rt();){
		y=x->f;
		if(!y->rt())	y->f->pdw();
		y->pdw();x->pdw();
		if(!y->rt())	(x->d()^y->d())?zig(x):zig(y);
		zig(x);
	}
}

void Access(Node *x){
	Node *t=x, *y=NIL;
	while(x!=NIL){
		splay(x);x->pdw();
		x->ISize+=x->s[1]->Size-y->Size;
		x->sc(y, 1);
		x->pup();
		y=x;x=x->f;
	}
	splay(t);
}

void Evert(Node *x){
	Access(x);x->mr();
}

void Cut(Node *x, Node *y){
	Evert(x);Access(y);
	x->f=NIL;y->s[0]=NIL;
	y->pup();
}

void Link(Node *x, Node *y){
	Evert(x);Access(y);
	x->f=y;
	y->ISize+=x->Size;
	y->Size+=x->Size;
}

int Qmax(Node *x, Node *y){
	Evert(x);Access(y);
	return y->MVat;
}

Node* GetRoot(Node *x){
	Access(x);
	while(x->s[0]!=NIL)	x=x->s[0];
	return x;
}

struct Edge{
	int x, y;
} E[MAXM];

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M;
	oddBlockCnt=N;
	
	for(int i=1;i<=N;++i){
		T[i]=new Node;
		T[i]->Id=i;
		T[i]->pup();
	}
	
	for(int i=1, x, y;i<=M;++i){
		T[N+i]=new Node;
		cin >> x >> y;
		cin >> T[N+i]->Val;
		T[N+i]->Id=N+i;
		T[N+i]->pup();
		E[i].x=x;E[i].y=y;
		if(GetRoot(T[x])!=GetRoot(T[y])){
			Evert(T[x]);
			if(((T[x]->Size+1)>>1)&1){
				--oddBlockCnt;
			}
			Link(T[x], T[N+i]);
			Evert(T[y]);
			if(((T[y]->Size+1)>>1)&1){
				--oddBlockCnt;
			}
			Link(T[N+i], T[y]);
			//Evert(T[y]);
			if(((T[y]->Size+1)>>1)&1)	++oddBlockCnt;
		}
		else{
			int z=Qmax(T[x], T[y]);
			if(T[N+i]->Val>=T[z]->Val){
				if(oddBlockCnt!=0){
					cout << "-1" << endl;
				}
				else{
					cout << st.rbegin()->first << endl;
				}
				continue;
			}
			Cut(T[E[z-N].x], T[z]);Cut(T[E[z-N].y], T[z]);
			Link(T[x], T[N+i]);Link(T[N+i], T[y]);
			st.erase(make_pair(T[z]->Val, z-N));
		}
		st.insert(make_pair(T[N+i]->Val, i));
		if(oddBlockCnt!=0){
			cout << "-1" << endl;
			continue;
		}
		while(true){
			int id=st.rbegin()->second;
			x=E[id].x;y=E[id].y;
			Evert(T[x]);
			Access(T[y]);
			if(((T[x]->Size+1)>>1)&1)	break;
			Cut(T[x], T[id+N]);Cut(T[id+N], T[y]);
			st.erase(*st.rbegin());
		}
		cout << st.rbegin()->first << endl;
	}
	
	return 0;
}