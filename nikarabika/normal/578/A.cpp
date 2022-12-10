#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;

#define INF (-1)

LL a, b;

LD get(LL val, LL an){
	LL k = val / (2 * an);
	if(val == a + b and k == 0)
		return INF;
	return LD(val) / LD((2 * k));
}

int main(){
	cin >> a >> b;
	cout.precision(10);
	if(a < b){
		cout << -1 << endl;
		return 0;
	}
	if(get(a + b, b) == -1){
		if(get(a - b, b) == -1)
			cout << -1 << endl;
		else
			cout << fixed << get(a - b, b) << endl;
	}
	else
		cout << fixed << min(get(a + b, b), get(a - b, b)) << endl;
	//cout << (min(get(a + b, b), get(a - b, b)) == -1 ? -1 : min(get(a + b, b), get(a - b, b))) << endl;
	return 0;
}