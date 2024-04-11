#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

int A, B;
string S;
bool field[400][400];

int main() {
    scanf("%d%d", &A, &B);
    cin>>S;
    LL x=0, y=0;
    field[y+200][x+200]=true;
    for (int i=0; i<int(S.size()); i++) {
	if (S[i]=='U') y++;
	if (S[i]=='D') y--;
	if (S[i]=='L') x--;
	if (S[i]=='R') x++;
	field[y+200][x+200]=true;
    }

    bool yes=false;
    for (int i=-200; i<200; i++) {
	for (int j=-200; j<200; j++) {
	    if (field[i+200][j+200]) {
		LL DX=A-j, DY=B-i;
		if (DX==0 && DY==0) yes=true;
		if (x!=0 && DX%x==0 && DX/x>=0 && y*(DX/x)==DY) yes=true;
		if (y!=0 && DY%y==0 && DY/y>=0 && x*(DY/y)==DX) yes=true;
	    }
	}
    }
    puts(yes?"Yes":"No");

    return 0;
}