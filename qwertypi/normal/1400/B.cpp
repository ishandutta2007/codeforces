#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int p, f; cin >> p >> f;
		int a, b, ca, cb;
		cin >> ca >> cb >> a >> b;
		if(a > b) swap(a, b), swap(ca, cb);
		if(ca >= p / a + f / a){
			cout << p / a + f / a << endl;
			continue;
		}
		int ans = 0;
		for(int i = 0; i <= ca; i++){
			int x = p - i * a, y = f - (ca - i) * a;
			if(x < 0) continue; if(y < 0) continue;
			ans = max(ans, min(x / b + y / b, cb));
		}
		cout << ans + ca << endl;
	}
}