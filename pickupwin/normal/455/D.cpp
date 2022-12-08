#include <cstdio>

const int MAXN=111111;

int N, M;
int Num[MAXN];
int Bs, Bc;
int Com, L, R, K, Ans=0;

int norm(int k){
	if(k<=0)	k+=N;
	if(k>N)	k-=N;
	return k;
}

struct Point{
	int x, y;
} P[MAXN];

struct Node{
	int data;
	Node *pre, *next;
	Node(){
		data=0;
		pre=this;next=this;
	}
};

Node *Noding(int k){
	Node *ret=new Node;
	ret->data=k;
	return ret;
}

struct Block{
	Node *Index;
	int Cnt[MAXN];
	int L, R;
	Block(){
		Index=new Node;
		for(int i=0;i<MAXN;++i)	Cnt[i]=0;
	}
	Node *Find(int at){
		Node *ret=Index;
		while(at--)	ret=ret->next;
		return ret;
	}
	void Del(Node *x){
		x->pre->next=x->next;
		x->next->pre=x->pre;
		--Cnt[x->data];
	}
	void Del(int at){
		Del(Find(at));
	}
	void Insert(Node *x, Node *p){
		x->pre=p;x->next=p->next;
		x->pre->next=x;x->next->pre=x;
		++Cnt[x->data];
	}
	void Insert(Node *x, int at){
		Insert(x, Find(at-1));
	}
} B[355];

int Count(Node *x, Node *y){
	int ret=0;
	for(Node *i=x;;i=i->next){
		if(i->data==K)	++ret;
		if(i==y)	break;
	}
	return ret;
}

int Ask(){
	int Bl=P[L].x, Br=P[R].x;
	int ret=0;
	for(int i=Bl+1;i<Br;++i)
		ret+=B[i].Cnt[K];
	if(Bl==Br){
		ret+=Count(B[Bl].Find(P[L].y), B[Bl].Find(P[R].y));
	}
	else{
		ret+=Count(B[Bl].Find(P[L].y), B[Bl].Index->pre);
		ret+=Count(B[Br].Index->next, B[Br].Find(P[R].y));
	}
	return ret;
}

void Update(){
	int Bl=P[L].x, Br=P[R].x;
	Node *Aim=B[Br].Find(P[R].y), *Temp;
	B[Br].Del(P[R].y);
	for(int i=Bl+1;i<=Br;++i){
		Temp=B[i-1].Index->pre;
		B[i-1].Del(Temp);
		B[i].Insert(Temp, B[i].Index);
	}
	B[Bl].Insert(Aim, P[L].y);
}

int min(int a, int b){
	return (a>b)?b:a;
}

void swap(int &a, int &b){
	int t=a;a=b;b=t;
}

int main(){
	
	scanf("%d", &N);
	for(int i=1;i<=N;++i)	scanf("%d", &Num[i]);
	
	for(Bs=0;Bs*Bs<N;++Bs);
	if(Bs+200<N)	Bs+=200;
	Bc=N/Bs;
	if(N%Bs!=0)	++Bc;
	
	for(int i=1;i<=Bc;++i){
		B[i].R=i*Bs;
		B[i].L=B[i].R-Bs+1;
		B[i].R=min(B[i].R, N);
	}
	
	for(int i=1;i<=Bc;++i)
		for(int j=B[i].L;j<=B[i].R;++j)
			B[i].Insert(Noding(Num[j]), B[i].Index->pre);
	
	P[1].x=1;P[1].y=1;
	for(int i=2;i<=N;++i){
		P[i].x=P[i-1].x;
		P[i].y=P[i-1].y+1;
		if(P[i].y>Bs){
			P[i].y-=Bs;
			++P[i].x;
		}
	}
	
	scanf("%d", &M);
	while(M--){
		scanf("%d%d%d", &Com, &L, &R);
		L=norm(L+Ans);R=norm(R+Ans);
		if(L>R)	swap(L, R);
		if(Com==2){
			scanf("%d", &K);
			K=norm(K+Ans);
			Ans=Ask();
			printf("%d\n", Ans);
		}
		else	Update();
	}
	
	return 0;
}