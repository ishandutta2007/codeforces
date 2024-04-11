#include <iostream>
#include <cassert>
#include <set>
#include <map>

using namespace std;

int N;
int Cnt=0;

struct Pos{
	int x, y;
	Pos(){}
	Pos(int _x, int _y){x=_x;y=_y;}
	void read(){cin >> x >> y;}
	long long l(){return 1LL*x*x+1LL*y*y;}
} op;

bool operator == (Pos A, Pos B){
	return A.x==B.x && A.y==B.y;
}

Pos operator + (Pos A, Pos B){
	return Pos(A.x+B.x, A.y+B.y);
}

int gcd(int a, int b){
	return (b==0)?a:gcd(b, a%b);
}

Pos Norm(Pos P){
	int g=gcd(P.x, P.y);
	P.x/=g;P.y/=g;
	return P;
}

struct cmpl{
	bool operator () (Pos A, Pos B){
		return A.l()<B.l();
	}
};

struct cmpxy{
	bool operator () (Pos A, Pos B){
		if(A.x==B.x)	return A.y<B.y;
		return A.x<B.x;
	}
};

multiset<Pos, cmpl> Set;
map<Pos, int, cmpxy> C, L;

void Push(Pos P){++Cnt;
	set<Pos, cmpl>::iterator it;
	it=Set.lower_bound(P);
	for(Pos Q;it!=Set.end();++it){
		Q=*it;
		if(Q.l()!=P.l())	break;
		++C[Norm(Q+P)];
	}
	++L[Norm(P)];
	Set.insert(P);
}

void Pull(Pos P){--Cnt;
	//Set.erase(P);
	set<Pos, cmpl>::iterator it, ik=Set.end();
	it=Set.lower_bound(P);
	for(Pos Q;it!=Set.end();++it){
		Q=*it;
		if(Q.l()!=P.l())	break;
		if(P==Q)	{ik=it;continue;}
		--C[Norm(Q+P)];
	}
	--L[Norm(P)];
	assert(ik!=Set.end());
	Set.erase(ik);
}

int Ask(Pos P){
	//cout << Cnt << " " << Set.size() << endl;
	assert((unsigned int)(Cnt)==Set.size());
	return Cnt-(C[Norm(P)]<<1)-L[Norm(P)];
}

int main(){
	
	cin >> N;
	
	for(int c;N--;){
		cin >> c;
		op.read();
		if(c==1){
			Push(op);
		}
		if(c==2){
			Pull(op);
		}
		if(c==3){
			cout << Ask(op) << endl;
		}
		//cout << Cnt << " ! " << Set.size() << endl;
	}
	
	return 0;
}