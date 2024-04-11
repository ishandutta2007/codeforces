#include <iostream>
#include <cmath>

using namespace std;

struct Point{
	double x, y;
	Point(){}
	Point(double _x, double _y){x=_x;y=_y;}
	void read(){
		cin >> x >> y;
	}
} P;

Point min(Point A, Point B){
	return Point(fmin(A.x, B.x), fmin(A.y, B.y));
}

Point max(Point A, Point B){
	return Point(fmax(A.x, B.x), fmax(A.y, B.y));
}

Point e45(Point P){
	return Point((P.x-P.y)/2.0, (P.x+P.y)/2.0);
}

Point u45(Point P){
	return Point(P.x+P.y, -P.x+P.y);
}

struct Square{
	Point Pl, Pr;
	Square(){Pl=Point(111.0, 111.0);Pr=Point(-111.0, -111.0);}
	void Ins(Point P){
		Pl=min(Pl, P);Pr=max(Pr, P);
	}
} S1, S2;

bool In(Point A, Square S){
	return (S.Pl.x<=A.x && A.x<=S.Pr.x && S.Pl.y<=A.y && A.y<=S.Pr.y);
}

int main(){
	ios_base::sync_with_stdio(false);
	
	for(int i=0;i<4;++i){
		P.read();
		S1.Ins(P);
	}
	
	for(int i=0;i<4;++i){
		P.read();
		S2.Ins(e45(P));
	}
	
	bool ANS=false;
	
	for(double i=S1.Pl.x;i<=S1.Pr.x;i+=1.0)
		if(In(e45(Point(i, S1.Pl.y)), S2) || In(e45(Point(i, S1.Pr.y)), S2))	ANS=true;
	for(double i=S1.Pl.y;i<=S1.Pr.y;i+=1.0)
		if(In(e45(Point(S1.Pl.x, i)), S2) || In(e45(Point(S1.Pr.x, i)), S2))	ANS=true;
	
	for(double i=S2.Pl.x;i<=S2.Pr.x;i+=1.0)
		if(In(u45(Point(i, S2.Pl.y)), S1) || In(u45(Point(i, S2.Pr.y)), S1))	ANS=true;
	for(double i=S2.Pl.y;i<=S2.Pr.y;i+=1.0)
		if(In(u45(Point(S2.Pl.x, i)), S1) || In(u45(Point(S2.Pr.x, i)), S1))	ANS=true;
	
	if(ANS)	puts("YES");
	else	puts("NO");
	
	return 0;
}