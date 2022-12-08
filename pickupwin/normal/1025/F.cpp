#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

const int MAXN=2011;

int N, M;

int To[MAXN];

struct Pos{
	long long x, y;
	int id;
	Pos(){}
	Pos(int _x, int _y){x=_x;y=_y;id=0;}
	void show(){
		cout << "(" << x << "," << y << ")";
	}
} P[MAXN], D, X, Y;

long long dot(Pos A, Pos B){
	return A.x*B.x+A.y*B.y;
}

bool cmpxy(Pos A, Pos B){
	if(A.x==B.x)	return A.y<B.y;
	return A.x<B.x;
}

bool cmpp(Pos A, Pos B){
	if(dot(A, X)==dot(B, X))	return dot(A, Y)<dot(B, Y);
	return dot(A, X)<dot(B, X);
}

Pos operator - (Pos A, Pos B){
	return Pos(A.x-B.x, A.y-B.y);
}

long long operator * (Pos A, Pos B){
	return A.x*B.y-A.y*B.x;
}

struct Pair{
	int Aid, Bid;
	Pos A, B;
	Pair(){}
	Pair(int _a, int _b){
		Aid=_a;Bid=_b;
		A=P[_a];B=P[_b];
	}
	//Pair(Pos _A, Pos _B){A=_A;B=_B;}
	Pos D(){return B-A;}
} R[MAXN*MAXN];

bool cmpr(Pair A, Pair B){
	return A.D()*B.D()>0LL;
}

long long C(int n){
	return 1LL*n*(n-1)/2LL;
}

long long Val(int a, int b){
	if(a<2 || b<2)	return 0LL;
	return C(a)*C(b);
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	for(int i=1;i<=N;++i)	cin >> P[i].x >> P[i].y;
	
	sort(P+1, P+N+1, cmpxy);
	
	for(int i=1;i<=N;++i)	P[i].id=i;
	
	/*
	for(int i=1;i<=N;++i){
		cout << i << " ";
		P[i].show();
		cout << endl;
	}
	*/
	
	for(int i=1;i<N;++i)
		for(int j=i+1;j<=N;++j)
			R[++M]=Pair(i, j);
	
	sort(R+1, R+M+1, cmpr);
	
	/*
	for(int i=1;i<=M;++i){
		R[i].D().show();
	}
	*/
	//R[1].A.show();R[1].B.show();
	//cout << endl;
	
	D=R[1].D();
	X=Pos(-D.y, D.x);Y=D;
	//X.show();Y.show();
	sort(P+1, P+N+1, cmpp);
	//for(int i=1;i<=N;++i)	P[i].show();
	//cout << endl;
	
	for(int i=1;i<=N;++i)	To[P[i].id]=i;
	
	long long Ans=0LL;
	
	for(int i=1, pa, pb;i<=M;++i){
		//cout << i << endl;
		pa=To[R[i].Aid];pb=To[R[i].Bid];
		assert(pa+1==pb);
		Ans+=Val(pa-1, N-pb);
		swap(P[pa], P[pb]);
		To[P[pa].id]=pa;To[P[pb].id]=pb;
	}
	
	cout << Ans << endl;
	
	return 0;
}