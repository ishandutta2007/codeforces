#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
const ld inc = 1.000000011;

ld kap(ld sk,int p){
	if(p==0)return 1;
	else{
		ld l = kap(sk,p/2);
		if(p%2==0)return l*l;
		else return l*l*sk;
	}	
}

int main(){
	int pak;
	ld ans;
	cin >> ans >> pak;
	ans *= kap(inc,pak);
	cout << fixed << setprecision(7) << ans << endl;
	return 0;
}