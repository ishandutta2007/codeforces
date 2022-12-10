#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const LL D = 1e9 + 7;
string a;
LL k, m, do_be_tavane_m, do_be_tavane_mk, kasr;
LL ans;

LL Pow(LL a, LL b){
	if(b == 0)
		return 1;
	LL t = Pow(a, b / 2);
	t = (t * t) % D;
	if(b & 1)
		t = (t * a) % D;
	return t;
}

LL Div(LL a, LL b){
	return (a * Pow(b, D - 2)) % D;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> a >> k;
	m = a.size();
	do_be_tavane_m = Pow(2, m);
	do_be_tavane_mk = Pow(do_be_tavane_m, k);
	kasr = Div(do_be_tavane_mk - 1, do_be_tavane_m - 1);
	for(int i = 0; i < m; i++)
		if((a[i] - '0') % 5 == 0)
			ans = (((Pow(2, i) * kasr) % D) + ans) % D;
	cout << ans << endl;
	return 0;
}