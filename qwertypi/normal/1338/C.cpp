#include <bits/stdc++.h>
#define int long long
using namespace std;

int Mat[4][3] = {
{0, 0, 0},
{1, 2, 3},
{2, 3, 1},
{3, 1, 2}
};

int32_t main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		int v;
		cin >> v;
		v--;
		int t1 = v / 3, t2 = v % 3;
		int s = 0;
		for(int i = 0; i < 30; i++){
			if(t1 < s + (1LL << i * 2)){
				t1 -= s;
				int ans = (1LL << i * 2) * (t2 + 1);
				for(int j = i - 1; j >= 0; j--){
					ans += (1LL << j * 2) * Mat[(t1 >> j * 2) % 4][t2];
				}
				cout << ans << endl;
				break;
			}
			s += (1LL << i * 2);
		}
	}
}