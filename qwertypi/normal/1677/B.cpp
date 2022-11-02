#include <bits/stdc++.h>

using namespace std;

const int NM = 1e6 + 13;
int a1[NM], a2[NM], s[NM], sc[NM], sr[NM];
bool ok_r[NM], ok_c[NM]; 
void solve(){
	int n, m;
	cin >> n >> m;
	string S;
	cin >> S;
	for(int i = 0; i < n * m; i++) s[i + 1] = s[i] + (S[i] == '1');
	for(int i = 0; i < n * m; i++){
		ok_c[i] = (i >= m ? ok_c[i - m] : 0) | (S[i] == '1');
		ok_r[i] = s[i + 1] - s[max(0, i + 1 - m)] > 0;
		sc[i] = (i > 0 ? sc[i - 1] : 0) + ok_c[i] - (i >= m ? ok_c[i - m] : 0);
		sr[i] = (i >= m ? sr[i - m] : 0) + ok_r[i];
	}
	for(int i = 0; i < n * m; i++){
		cout << sc[i] + sr[i] << ' ';
	}
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}