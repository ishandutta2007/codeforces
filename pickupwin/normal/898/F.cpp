#include <iostream>
#include <string>
using namespace std;
const int MAXL=1111111;
int P[7]={10007, 15991, 16001, 19997, 23333, 38039, 41777};
int Num[MAXL], L;
int Pw[7][MAXL], Ha[7][MAXL];
int AL, AR, BL, BR, ANSL, ANSR;
int ansl, abl;
string input;
bool same(int a, int b, int m){
	a=(a%m+m)%m;
	b=(b%m+m)%m;
	return (a==b);
}
bool test(){
	int HA, HB, HANS;
	for(int i=0;i<7;++i){
		HA=Ha[i][AR]-Ha[i][AL-1]*Pw[i][AR-AL+1];
		HB=Ha[i][BR]-Ha[i][BL-1]*Pw[i][BR-BL+1];
		HANS=Ha[i][ANSR]-Ha[i][ANSL-1]*Pw[i][ANSR-ANSL+1];
		if(!same(HA+HB, HANS, P[i]))	return false;
	}
	return true;
}
void show(){
	for(int i=AL;i<=AR;++i)	cout << Num[i];
	cout << "+";
	for(int i=BL;i<=BR;++i)	cout << Num[i];
	cout << "=";
	for(int i=ANSL;i<=ANSR;++i)	cout << Num[i];
	cout << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin >> input;
	L=input.length();
	for(int i=1;i<=L;++i)	Num[i]=input[i-1]-'0';
	for(int i=0;i<7;++i){
		Pw[i][0]=1;
		for(int j=1;j<=L;++j)	Pw[i][j]=(Pw[i][j-1]*10)%P[i];
	}
	for(int i=0;i<7;++i){
		Ha[i][0]=0;
		for(int j=1;j<=L;++j)	Ha[i][j]=(Ha[i][j-1]*10+Num[j])%P[i];
	}
	ANSR=L;AL=1;
	bool Can;
	for(ANSL=L;ANSL>=1;--ANSL){
		ansl=ANSR-ANSL+1;abl=L-ansl;
		if(abl<=(ansl)<<1 && abl>=ansl){
			AR=ansl;BL=AR+1;BR=ANSL-1;Can=true;
			if(AL<=AR && BL<=BR){
				if(Num[AL]==0 && AL<AR)	Can=false;
				if(Num[BL]==0 && BL<BR)	Can=false;
				if(Num[ANSL]==0 && ANSL<ANSR)	Can=false;
				if(Can && test()){
					show();
					return 0;
				}
			}
			AR=ansl-1;BL=AR+1;BR=ANSL-1;Can=true;
			if(AL<=AR && BL<=BR){
				if(Num[AL]==0 && AL<AR)	Can=false;
				if(Num[BL]==0 && BL<BR)	Can=false;
				if(Num[ANSL]==0 && ANSL<ANSR)	Can=false;
				if(Can && test()){
					show();
					return 0;
				}
			}
			BL=ANSL-ansl;BR=ANSL-1;AR=BL-1;Can=true;
			if(AL<=AR && BL<=BR){
				if(Num[AL]==0 && AL<AR)	Can=false;
				if(Num[BL]==0 && BL<BR)	Can=false;
				if(Num[ANSL]==0 && ANSL<ANSR)	Can=false;
				if(Can && test()){
					show();
					return 0;
				}
			}
			BL=ANSL-ansl+1;BR=ANSL-1;AR=BL-1;Can=true;
			if(AL<=AR && BL<=BR){
				if(Num[AL]==0 && AL<AR)	Can=false;
				if(Num[BL]==0 && BL<BR)	Can=false;
				if(Num[ANSL]==0 && ANSL<ANSR)	Can=false;
				if(Can && test()){
					show();
					return 0;
				}
			}
		}
	}
	return 0;
}