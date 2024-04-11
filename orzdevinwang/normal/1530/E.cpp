#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
using namespace std;
const int N = 4e5 + 7;
int n, cnt[26];
char s[N];
void Main () {
	L(i, 0, 25) cnt[i] = 0;
	
	cin >> (s + 1), n = strlen(s + 1);
	L(i, 1, n) cnt[s[i] - 'a'] ++; 
	
	bool all = true;
	L(i, 0, 25) if(cnt[i] == n) all = false;
	if(!all) {
		L(i, 1, n) cout << s[i];
		cout << "\n";
		return ;
	}
	
	int mn = 0;
	R(i, 25, 0) if(cnt[i]) mn = i;
	L(i, 0, 25) if(cnt[i] == 1) {
		cout << (char) (i + 'a'), cnt[i] --;
		L(i, 0, 25) {
			while(cnt[i]) {
				cout << (char) (i + 'a');
				--cnt[i]; 
			}
		}
		cout << "\n";
		return ;
	}
	if(cnt[mn] * 2 - 2 <= n) { 
		cout << (char) (mn + 'a') << (char) (mn + 'a'), cnt[mn] -= 2;
		L(i, mn + 1, 25) {
			while(cnt[i]) {
				cout << (char) (i + 'a');
				if(cnt[mn]) cout << (char) (mn + 'a'), --cnt[mn];
				--cnt[i];
			}
		} 
	}
	else {
		cout << (char) (mn + 'a');
		-- cnt[mn];
		
		int nxt = mn + 1;
		while (!cnt[nxt]) ++nxt;
		
		if(cnt[nxt] + cnt[mn] + 1 == n) {
			L(i, 1, cnt[nxt]) cout << (char) (nxt + 'a');
			L(i, 1, cnt[mn]) cout << (char) (mn + 'a'); 
		} 
		else {
			-- cnt[nxt], cout << (char) (nxt + 'a');
			while (cnt[mn]) cout << (char) (mn + 'a'), -- cnt[mn]; 
			
			int nnxt = nxt + 1;
			while (!cnt[nnxt]) ++nnxt;
			
			cout << (char) (nnxt + 'a'), -- cnt[nnxt];
			L(i, 0, 25) while(cnt[i]) cout << (char) (i + 'a'), -- cnt[i];
		}
	}
	cout << "\n";
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	int T;
	cin >> T;
	while (T--) Main(); 
	return 0;
}