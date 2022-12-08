#include <iostream>

using namespace std;

struct Pos{
	int x, y;
	Pos(){}
	Pos(int _x, int _y){x=_x;y=_y;}
	void show(){
		cout << x << " " << y << endl;
	}
} A, B, C;

Pos Out[1111111];
int Oc;

bool cmpxy(Pos A, Pos B){
	if(A.x==B.x)	return A.y<B.y;
	return A.x<B.x;
}

void Open(int x, int y){
	Out[++Oc]=Pos(x, y);
}

void Go(Pos A, Pos B){
	for(int i=A.x;i>B.x;--i)	Open(i, A.y);
	for(int i=A.x;i<B.x;++i)	Open(i, A.y);
	for(int i=A.y;i<B.y;++i)	Open(B.x, i);
	for(int i=A.y;i>B.y;--i)	Open(B.x, i);
}

void Show(){
	cout << Oc << endl;
	for(int i=1;i<=Oc;++i){
		Out[i].show();
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> A.x >> A.y;
	cin >> B.x >> B.y;
	cin >> C.x >> C.y;
	
	if(cmpxy(B, A))	swap(A, B);
	if(cmpxy(C, B))	swap(B, C);
	if(cmpxy(B, A))	swap(A, B);
	
	int yl=min(A.y, C.y), yr=max(A.y, C.y);
	if(B.y<yl){
		for(int i=B.y;i<yl;++i)	Open(B.x, i);
		B.y=yl;
	}
	else if(B.y>yr){
		for(int i=B.y;i>yr;--i)	Open(B.x, i);
		B.y=yr;
	}
	Go(A, B);Go(B, C);
	Open(C.x, C.y);
	
	Show();
	
	return 0;
}