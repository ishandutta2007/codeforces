#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

vector <LL> v;
LL n;

void F(LL x, int C){
	if(C == 0){
		v.push_back(x);
		return;
	}
	F(x * 10 + 4, C - 1);
	F(x * 10 + 7, C - 1);
}

int main(){
	cin >> n;
	for(int i = 1; i <= 9; i++)
		F(0, i);
	cout << lower_bound(v.begin(), v.end(), n) - v.begin() + 1 << endl;
}