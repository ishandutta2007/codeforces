#include <cstdio>
#include <iostream>
using namespace std;

#define f(x) for(int i = 0; i < x; ++i)
char S[9];

int main() {
	int CX = 0 , CO = 0 , WinX = 0 , WinO = 0;
	f(9) {
		cin >> S[i];
		if (S[i] == 'X') ++CX;
		if (S[i] == '0') ++CO;
	}
	f(3) {
		if (S[3*i] == S[3*i+1] && S[3*i] == S[3*i+2]){
			if (S[3*i] == 'X') WinX = 1;
			if (S[3*i] == '0') WinO = 1;
		}
		if (S[i] == S[i+3] && S[i] == S[i+6]){
			if (S[i] == 'X') WinX = 1;
			if (S[i] == '0') WinO = 1;
		}
	}
	if (S[0] == S[4] && S[4] == S[8] || S[2] == S[4] && S[4] == S[6]){
		if (S[4] == 'X') WinX = 1;
		if (S[4] == '0') WinO = 1;
	}
	if (WinX && CX!=CO+1 || WinO && CX!=CO || CX!=CO+1 && CX!=CO)
		puts("illegal");
	else if (WinX) puts("the first player won");
	else if (WinO) puts("the second player won");
	else if (CX + CO == 9) puts("draw");
	else if (CX == CO) puts("first");
	else puts("second");
	return 0;
}