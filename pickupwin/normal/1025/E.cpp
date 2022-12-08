#include <cstdio>
#include <cassert>
#include <algorithm>

using std::swap;
using std::sort;

const int MAXN=55;
const int MAXM=55;
const int MAXS=11111;

int N, M;
int Cnt;
bool Inv=false;

struct Pos{
	int x, y;
	Pos(){}
	Pos(int _x, int _y){x=_x;y=_y;}
	void read(){
		scanf("%d%d", &x, &y);
	}
};

bool operator == (Pos A, Pos B){
	return A.x==B.x && A.y==B.y;
}

bool cmpp(Pos A, Pos B){
	if(A.x==B.x){
		if(A.x+B.x==2)	return A.y<B.y;
		return A.y>B.y;
	}
	return A.x<B.x;
}

struct Move{
	Pos A, B;
	Move(){}
	Move(Pos a, Pos b){A=a;B=b;}
	int len(){
		return abs(A.x-B.x)+abs(A.y-B.y);
	}
	void zig(){
		swap(A, B);
	}
	void show(){
		if(Inv){
			A.x=N+1-A.x;
			B.x=N+1-B.x;
		}
		if(A.x==B.x){
			if(A.y<B.y){
				for(int i=A.y;i<B.y;++i)
					printf("%d %d %d %d\n", A.x, i, A.x, i+1);
			}
			if(A.y>B.y){
				for(int i=A.y;i>B.y;--i)
					printf("%d %d %d %d\n", A.x, i, A.x, i-1);
			}
		}
		if(A.y==B.y){
			if(A.x<B.x){
				for(int i=A.x;i<B.x;++i)
					printf("%d %d %d %d\n", i, A.y, i+1, A.y);
			}
			if(A.x>B.x){
				for(int i=A.x;i>B.x;--i)
					printf("%d %d %d %d\n", i, A.y, i-1, A.y);
			}
		}
	}
} P[2][MAXS];

int Pc[2];

void show(){
	Cnt=0;
	for(int i=1;i<=Pc[0];++i)	Cnt+=P[0][i].len();
	for(int i=1;i<=Pc[1];++i)	Cnt+=P[1][i].len();
	printf("%d\n", Cnt);
	for(int i=1;i<=Pc[0];++i)
		P[0][i].show();
	for(int i=Pc[1];i>=1;--i){
		P[1][i].zig();
		P[1][i].show();
	}
}

void Push(Pos A, Pos B, int d){
	if(A==B)	return;
	assert(A.x==B.x || A.y==B.y);
	P[d][++Pc[d]]=Move(A, B);
}

void Jump(Pos A, Pos B, int d){
	if(A==B)	return;
	Pos Temp;
	if(A.y>B.y)	Temp=Pos(B.x, A.y);
	else	Temp=Pos(A.x, B.y);
	Push(A, Temp, d);
	Push(Temp, B, d);
}

void Jump_zig(Pos A, Pos B, int d){
	if(A.y==B.y)	{Push(A, B, d);return;}
	Pos Temp1, Temp2;
	Temp1=Pos(A.x-1, A.y);
	Temp2=Pos(B.x+1, B.y);
	Push(A, Temp1, d);
	Push(Temp1, Temp2, d);
	Push(Temp2, B, d);
}

struct Cube{
	Pos P;
	int id;
} S[MAXM], T[MAXM];

bool operator < (Cube A, Cube B){
	return cmpp(A.P, B.P);
}

int main(){
	
	scanf("%d%d", &N, &M);
	
	for(int i=1;i<=M;++i){
		S[i].P.read();
		S[i].id=i;
	}
	
	for(int i=1;i<=M;++i){
		T[i].P.read();
		T[i].id=i;
	}
	
	if(M==1){
		Jump(S[1].P, T[1].P, 0);
		show();
		return 0;
	}
	
	/*
	Cnt=0;
	for(int i=1;i<=M;++i){
		if(S[i].P.x>(N+1-S[i].P.x))	++Cnt;
		if(T[i].P.x>(N+1-T[i].P.x))	++Cnt;
	}
	
	if(Cnt>M){
		Inv=true;
		//puts("!!!");
		for(int i=1;i<=M;++i){
			S[i].P.x=(N+1-S[i].P.x);
			T[i].P.x=(N+1-T[i].P.x);
		}
	}
	*/
	
	sort(S+1, S+M+1);
	//for(int i=1;i<=M;++i)
	//	printf("!%d %d\n", S[i].P.x, S[i].P.y);
	for(int i=1;i<=M;++i)
		Jump(S[i].P, Pos(1, i), 0);
	if(N==2){
		if(S[1].id>S[2].id){
			Push(Pos(1, 2), Pos(2, 2), 0);
			Push(Pos(1, 1), Pos(1, 2), 0);
			Push(Pos(2, 2), Pos(2, 1), 0);
			Push(Pos(2, 1), Pos(1, 1), 0);
		}
	}
	else{
		for(int i=1;i<=M;++i)	Push(Pos(1, i), Pos(3, i), 0);
		for(int i=1;i<=M;++i)	Jump_zig(Pos(3, i), Pos(1, S[i].id), 0);
	}
	
	sort(T+1, T+M+1);
	for(int i=1;i<=M;++i)
		Jump(T[i].P, Pos(1, i), 1);
	if(N==2){
		if(T[1].id>T[2].id){
			Push(Pos(1, 2), Pos(2, 2), 1);
			Push(Pos(1, 1), Pos(1, 2), 1);
			Push(Pos(2, 2), Pos(2, 1), 1);
			Push(Pos(2, 1), Pos(1, 1), 1);
		}
	}
	else{
		for(int i=1;i<=M;++i)	Push(Pos(1, i), Pos(3, i), 1);
		for(int i=1;i<=M;++i)	Jump_zig(Pos(3, i), Pos(1, T[i].id), 1);
	}
	
	show();
	
	return 0;
}