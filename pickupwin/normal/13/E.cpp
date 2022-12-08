#include <iostream>

using namespace std;

const int MAXN=111111;

int N, M;
int Num[MAXN];

struct Node{
	int Cnt, Id;
	int r;
	Node *s[2], *f;
	
	Node(bool i=false);
	
	int d(){return f->s[1]==this;}
	void sc(Node *x, int d){(s[d]=x)->f=this;}
	bool rt(){return f->s[1]!=this && f->s[0]!=this;}
	
	void pup(){Cnt=s[0]->Cnt+1+s[1]->Cnt;}
	void mr(){r^=1;swap(s[0], s[1]);}
	void pdw(){if(r!=0){s[0]->mr();s[1]->mr();r=0;}}
	
} *NIL=new Node(true), *T[MAXN];

Node::Node(bool i){
	if(i){s[0]=NULL;s[1]=NULL;f=NULL;Cnt=0;Id=0;r=0;}
	else{s[0]=NIL;s[1]=NIL;f=NIL;Cnt=1;Id=0;r=0;}
}

void zig(Node *x){
	int d=x->d();
	Node *y=x->f;
	y->sc(x->s[!d], d);
	if(y->rt())	x->f=y->f;
	else	y->f->sc(x, y->d());
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

Node *GetRoot(Node *x){
	Access(x);
	while(x->s[0]!=NIL)	x=x->s[0];
	return x;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M;
	for(int i=1;i<=N;++i)	cin >> Num[i];
	
	for(int i=1;i<=N;++i)	{T[i]=new Node;T[i]->Id=i;}
	
	for(int i=1;i<=N;++i){
		if(i+Num[i]<=N)	T[i]->f=T[i+Num[i]];
	}
	
	for(int t, a, b;M--;){
		cin >> t >> a;
		if(t==0){
			cin >> b;
			if(a+Num[a]<=N){
				Access(T[a]);
				T[a]->s[0]->f=NIL;
				T[a]->s[0]=NIL;
				T[a]->pup();
			}
			Num[a]=b;
			if(a+Num[a]<=N){
				Access(T[a]);
				T[a]->f=T[a+Num[a]];
			}
		}
		else{
			Access(T[a]);
			t=T[a]->Cnt;
			a=GetRoot(T[a])->Id;
			cout << a << " " << t << endl;
		}
		//Evert(End);
		//show();
	}
	
	return 0;
}