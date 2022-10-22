#include <bits/stdc++.h>

using namespace std;
typedef long long int li;
typedef pair<int,int> pii;
typedef pair<li,li> pll;
#define mp make_pair
#define pb push_back

long long t, a, b, l, r, q, ans[40005];


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		cin >> a >> b >> q;
		for (int i=0; i<40005; i++){
			ans[i] = 0;
		}
		for (int i=1; i<=a*b; i++){
			if ((i%a)%b != (i%b)%a){
				ans[i] = ans[i-1] + 1;
			}
			else ans[i] = ans[i-1];
		}
		while (q--){
			cin >> l >> r;
			long long x = (r-l)/(a*b);
			long long thing = 0;
			thing += x * ans[a*b];
			long long y = l%(a*b), z = r%(a*b);
			if (y == 0) y+= a*b;
			if (z==0) z += a*b;
			if (z>=y) thing += ans[z] - ans[y-1];
			else {
				thing += ans[z] + ans[a*b] - ans[y-1];
			}
			cout << thing << " ";
		}
		cout << "\n";
	}
}