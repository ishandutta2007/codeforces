#include <bits/stdc++.h>

using namespace std;
int main(){
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	int t_a = a;
	int t_b = min(b, c);
	if(e < f){
		swap(e, f);
		swap(t_a, t_b);
	}
	int st;
	int ans = 0;
	st = min(d, t_a);
	ans += st * e;
	d -= st;
	st = min(d, t_b);
	ans += st * f;
	cout << ans << endl;
}