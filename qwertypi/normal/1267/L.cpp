#include <bits/stdc++.h>

using namespace std;
char A[1001][1001];
int main(){
	int n, l, k;
	cin >> n >> l >> k;
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	int L = 0, R = s.size() - 1;
	int lst = 0;
	for(int i = 0; i < l; i++){
		for(int j = 0; j < lst; j++){
			A[j][i] = s[R - lst + j + 1];
		}
		R -= lst;
		char c = ' ';
		int cnt = 0;
		for(int j = lst; j < k; j++){
			A[j][i] = s[L];
			if(s[L] != c){
				cnt = 1;
				c = s[L];
			}else{
				cnt++;
			}
			L++;
		}
		for(int j = k; j < n; j++){
			A[j][i] = s[R - n + j + 1];
		}
		R -= (n - k);
		lst = k - cnt;
	}
	for(int j = 0; j < n; j++){
		for(int i = 0; i < l; i++){
			cout << A[j][i];
		}
		cout << endl;
	}
}