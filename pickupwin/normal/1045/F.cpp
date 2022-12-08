#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN=200111;

int N;

struct Pos{
	int x, y;
	int id;
	Pos(){}
	Pos(int _x, int _y){x=_x;y=_y;}
	Pos(int _x, int _y, int _id){x=_x;y=_y;id=_id;}
	bool e(){return !((x&1)|(y&1));}
};

bool cmpxy(Pos A, Pos B){
	if(A.x==B.x)	return A.y<B.y;
	return A.x<B.x;
}

Pos operator + (Pos A, Pos B){
	return Pos(A.x+B.x, A.y+B.y);
}

Pos operator - (Pos A, Pos B){
	return Pos(A.x-B.x, A.y-B.y);
}

long long operator * (Pos A, Pos B){
	return 1LL*A.x*B.y-1LL*A.y*B.x;
}

Pos In[MAXN];
bool Vis[MAXN];
bool Vis00;

typedef vector<Pos> Pack;

Pos P[MAXN], U[MAXN], D[MAXN];
int Pc, Uc, Dc;

void Norm(Pack &Pa){
	Pc=Pa.size();
	for(int i=1;i<=Pc;++i)	P[i]=Pa[i-1];
	sort(P+1, P+Pc+1, cmpxy);
	Uc=0;
	U[++Uc]=P[1];
	for(int i=2;i<=Pc;++i){
		while(Uc>1 && (U[Uc]-U[Uc-1])*(P[i]-U[Uc])>=0LL)	--Uc;
		U[++Uc]=P[i];
	}
	Dc=0;
	D[++Dc]=P[Pc];
	for(int i=Pc-1;i;--i){
		while(Dc>1 && (D[Dc]-D[Dc-1])*(P[i]-D[Dc])>=0LL)	--Dc;
		D[++Dc]=P[i];
	}
	Pa.clear();
	for(int i=1;i<=Uc;++i)	Pa.push_back(U[i]);
	for(int i=2;i<Dc;++i)	Pa.push_back(D[i]);
}

bool Even(Pack &P){
	bool ret=true;
	for(int i=0, s=P.size();i<s && ret;++i){
		ret&=P[i].e();
	}
	return ret;
}

Pack Tot, Left, Right;

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	
	for(int i=1, a, b;i<=N;++i){
		cin >> a >> b;
		Vis00|=(a==0 && b==0);
		In[i]=Pos(a, b, i);
	}
	
	for(int i=1;i<=N;++i){
		Tot.push_back(In[i]);
	}
	if(!Vis00)	Tot.push_back(Pos(0, 0));
	
	Norm(Tot);
	
	for(int i=1, s=Tot.size();i<s;++i){
		Vis[Tot[i].id]=true;
		((i&1)?Left:Right).push_back(Tot[i]);
	}
	
	for(int i=1;i<=N;++i){
		if(!Vis[i]){
			Left.push_back(In[i]);
			Right.push_back(In[i]);
		}
	}
	Left.push_back(Pos(0, 0));
	Right.push_back(Pos(0, 0));
	
	Norm(Left);
	Norm(Right);
	
	if(Even(Left) && Even(Right))	cout << "Borna" << endl;
	else	cout << "Ani" << endl;
	
	return 0;
}