#include <iostream>
#include <map>
//#include <fstream>

using namespace std;

//ifstream cin("CF813F.txt", ios_base::in);

const int MAXN=1111111;
const int MAXM=1111111;
const int INF=1034567890;

int N, M;
int OddCnt=0;

struct Node{
	int Size, Val, MVat, MinV, Id;
	int r;
	
	Node *s[2], *f;
	
	Node(bool i=false);
	
	int d(){return f->s[1]==this;}
	void sc(Node *x, int d){(s[d]=x)->f=this;}
	bool rt(){return f->s[0]!=this && f->s[1]!=this;}
	
	void pup(){
		Size=s[0]->Size+s[1]->Size+1;
		MinV=Val;
		MinV=min(MinV, s[0]->MinV);
		MinV=min(MinV, s[1]->MinV);
		if(MinV==Val)	MVat=Id;
		if(MinV==s[0]->MinV)	MVat=s[0]->MVat;
		if(MinV==s[1]->MinV)	MVat=s[1]->MVat;
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
	r=0;Size=0;Val=INF;MVat=-1;Id=-1;MinV=INF;
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
		x->sc(y, 1);x->pup();
		y=x;x=x->f;
	}
	splay(t);
}

void Evert(Node *x){
	Access(x);x->mr();
}

void Cut(Node *x, Node *y){
	Evert(x);Access(y);
	x->f=NIL;y->s[0]=NIL;y->pup();
}

void Link(Node *x, Node *y){
	Evert(x);x->f=y;
}

Node *GetRoot(Node *x){
	Access(x);
	while(x->s[0]!=NIL)	x=x->s[0];
	return x;
}

int Qmin(Node *x, Node *y){
	Evert(x);Access(y);
	return y->MVat;
}

int mark[MAXM];
struct Edge{
	int x, y;
} E[MAXM];

struct Query{
	int op, id;
} Q[MAXM];

map< pair<int, int>, int>	Map;
int m=0;


int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M;

	for(int i=1;i<=N;++i){
		T[i]=new Node;
		T[i]->Id=i;
		T[i]->pup();
	}
	
	for(int i=1;i<=M;++i){
		T[N+i]=new Node;
		T[N+i]->Id=N+i;
		T[N+i]->pup();
	}
	
	for(int i=1, x, y, id;i<=M;++i){
		cin >> x >> y;
		if(x<y)	swap(x, y);
		id=Map[make_pair(x, y)];
		if(id!=0){
			Q[i].op=0;Q[i].id=id;
			Map[make_pair(x, y)]=0;
			T[N+id]->Val=i;
		}
		else{
			Q[i].op=1;Q[i].id=++m;
			E[m].x=x;E[m].y=y;
			Map[make_pair(x, y)]=m;
		}
	}
	
	for(int i=1;i<=M;++i){
		if(T[N+i]->Val==INF)	T[N+i]->Val=M+1;
		T[N+i]->pup();
	}
	
	for(int i=1, x, y;i<=M;++i){
		x=E[Q[i].id].x;y=E[Q[i].id].y;
		if(Q[i].op){
			if(GetRoot(T[x])!=GetRoot(T[y])){
				Link(T[x], T[N+Q[i].id]);
				Link(T[N+Q[i].id], T[y]);
			}
			else{
				int z=Qmin(T[x], T[y]);
				Evert(T[x]);Access(T[y]);
				if(((T[y]->Size-1)>>1)&1){
					if(T[N+Q[i].id]->Val<=T[z]->Val)	mark[Q[i].id]=2;
					else{
						mark[z-N]=2;
						Cut(T[E[z-N].x], T[z]);Cut(T[E[z-N].y], T[z]);
						Link(T[x], T[N+Q[i].id]);Link(T[N+Q[i].id], T[y]);
					}
				}
				else{
					++OddCnt;
					if(T[N+Q[i].id]->Val<=T[z]->Val)	mark[Q[i].id]=1;
					else{
						mark[z-N]=1;
						Cut(T[E[z-N].x], T[z]);Cut(T[E[z-N].y], T[z]);
						Link(T[x], T[N+Q[i].id]);Link(T[N+Q[i].id], T[y]);
					}
				}
			}
		}
		else{
			if(!mark[Q[i].id]){
				Cut(T[x], T[N+Q[i].id]);
				Cut(T[N+Q[i].id], T[y]);
			}
			else if(mark[Q[i].id]==1)	--OddCnt;
		}
		puts(OddCnt?"NO":"YES");
	}
	
	return 0;
}