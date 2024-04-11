#include <bits/stdc++.h>
#define int long long
using namespace std;

int c[101];
int F[101], SF[101];
int ok[101];
int sp[101];
void solve(){
	fill(ok, ok + 101, false);
	fill(sp, sp + 101, false);
	vector<int> v;
	int k;
	cin >> k;
	for(int i = 0; i < k; i++){
		cin >> c[i];
	}
	int mx = 0, s = accumulate(c, c + k, 0LL);
	for(int i = 0;; i++){
		if(SF[i] > s){
			cout << "NO" << endl;
			return;
		}else if(SF[i] == s){
			mx = i;
			break;
		}
	}
	bool failed = false;
	for(int i = 0; i < k; i++){
		for(int j = 80; j >= 1; j--){
			if(c[i] == F[j] && (j % 2 == 0)){
				c[i] -= F[j];
				sp[j]++;
			}else if(c[i] >= F[j]){
				c[i] -= F[j];
				ok[j]++;
				j--;
			}
		}
		if(c[i] != 0) failed = true;
		if(failed) break;
	}
	if(failed){
		cout << "NO" << endl;
		return;
	}
	for(int j = 80; j >= 0; j--){
		if(sp[j] && !ok[j] && j <= mx) sp[j]--, ok[j]++;
		if(sp[j] >= 2){
			cout << "NO" << endl;
			return;
		}
		if(sp[j]){
			int v = F[j];
			for(int l = j - 1; l >= 1; l--){
				if(v >= F[l]){
					v -= F[l];
					ok[l]++;
					l--;
				}
			}
			sp[j]--;
		}
	}
	if(ok[1] == 0 && ok[2] >= 1) ok[1]++, ok[2]--;
	for(int i = 0; i <= 80; i++){
		if(ok[i] >= 2){
			cout << "NO" << endl;
			return;
		}
	}
	int la = 0;
	for(int i = 80; i >= 0; i--){
		if(ok[i]) la = max(la, i);
	}
	for(int j = la; j >= 1; j--){
		if(ok[j] != 1){
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}

int32_t main(){
	F[0] = 0, F[1] = 1;
	for(int i = 2; i <= 80; i++) F[i] = F[i - 1] + F[i - 2];
	for(int i = 1; i <= 80; i++) SF[i] = SF[i - 1] + F[i];
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}