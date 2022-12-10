#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

LL N;

void F(LL x, int R, int B){
	if(R < 0 or B < 0)
		return;
	if(R == 0 and B == 0){
		if(x >= N){
			cout << x << endl;
			exit(0);
		}
		return;
	}
	F(x * 10 + 4, R - 1, B);
	F(x * 10 + 7, R, B - 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> N;
	LL x = N;
	int c = 0;
	while(x)
		x /= 10, c++;
	c = (c + 1) / 2;
	F(0, c, c);
	F(0, c + 1, c + 1);
	return 0;
}