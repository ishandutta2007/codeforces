#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

const int MAXN=200111;
const int MAXM=200111;

int N, M;
int A[MAXN], B[MAXN];
bool Out[MAXM];
int Ans[MAXM];

struct Pos{
	int x, y;
} P[MAXN];

struct Query{
	int x, y, b, v, id;
	Query(){}
	Query(int _x, int _y, int _b, int _v, int _id){x=_x;y=_y;b=_b;v=_v;id=_id;}
} Q[MAXN+(MAXM<<2)];

bool cmpxyi(Query A, Query B){
	if(A.x==B.x){
		if(A.y==B.y)	return A.id<B.id;
		return A.y<B.y;
	}
	return A.x<B.x;
}

int Qc;

void Push(Pos P, int v){
	++Qc;
	Q[Qc].x=P.x;Q[Qc].y=P.y;
	Q[Qc].b=0;Q[Qc].v=v;
	Q[Qc].id=Qc;
}

int C[MAXN];

int lowbit(int a){
	return a&(-a);
}

void Add(int at, int d){
	assert(at);
	for(int i=at;i<=N;i+=lowbit(i))
		C[i]+=d;
}

int Ask(int at){
	int ret=0;
	for(int i=at;i>0;i-=lowbit(i))
		ret+=C[i];
	return ret;
}

void Deal(int l, int r){
	if(l==r)	return;
	int m=(l+r)>>1;
	Deal(l, m);Deal(m+1, r);
	sort(Q+l, Q+r+1, cmpxyi);
	for(int i=l;i<=r;++i){
		if(Q[i].id<=m && Q[i].b==0)
			Add(Q[i].y, Q[i].v);
		else if(Q[i].id>m && Q[i].b!=0)	Q[i].v+=Ask(Q[i].y);
	}
	for(int i=l;i<=r;++i)	if(Q[i].id<=m && Q[i].b==0)	Add(Q[i].y, -Q[i].v);
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M;
	for(int i=1;i<=N;++i)	cin >> A[i];
	for(int i=1;i<=N;++i)	cin >> B[i];
	
	for(int i=1;i<=N;++i){
		P[A[i]].x=i;
		P[B[i]].y=i;
	}
	
	for(int i=1;i<=N;++i){
		Push(P[i], 1);
	}
	
	for(int i=1, t, xl, xr, yl, yr;i<=M;++i){
		cin >> t;
		if(t==1){
			cin >> xl >> xr >> yl >> yr;
			++Qc;Q[Qc]=Query(xr, yr, i, 0, Qc);
			++Qc;Q[Qc]=Query(xr, yl-1, -i, 0, Qc);
			++Qc;Q[Qc]=Query(xl-1, yr, -i, 0, Qc);
			++Qc;Q[Qc]=Query(xl-1, yl-1, i, 0, Qc);
			Out[i]=true;
		}
		else{
			cin >> yl >> yr;
			swap(B[yl], B[yr]);
			Push(P[B[yl]], -1);
			P[B[yl]].y=yl;
			Push(P[B[yl]], 1);
			Push(P[B[yr]], -1);
			P[B[yr]].y=yr;
			Push(P[B[yr]], 1);
		}
	}
	
	Deal(1, Qc);
	
	for(int i=1;i<=Qc;++i){
		if(Q[i].b!=0){
			if(Q[i].b>0){
				Ans[Q[i].b]+=Q[i].v;
			}
			else	Ans[-Q[i].b]-=Q[i].v;
		}
	}
	
	for(int i=1;i<=M;++i){
		if(Out[i]){
			cout << Ans[i] << endl;
		}
	}
	
	return 0;
}