							/* in the name of Allah */
#include <iostream>
using namespace std;

int n, cnt[1010];

int main(){
	while(cin >> n){
		memset(cnt, 0, sizeof cnt);
		int a;
		for(int i = 0; i < n; i++){
			cin >> a;
			cnt[a]++;
		}
		int mx = 0, ted = 0;
		for(int i = 0; i <= 1000; i++){
			mx = max(mx, cnt[i]);
			ted += (cnt[i] > 0 ? 1 : 0);
		}
		cout << mx << ' ' << ted << endl;
	}
	return 0;
}