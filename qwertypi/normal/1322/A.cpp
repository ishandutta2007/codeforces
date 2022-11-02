#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int c1 = count(s.begin(), s.end(), '(');
	int c2 = count(s.begin(), s.end(), ')');
	
	int ans = 0;
	if(c1 != c2){
		cout << -1 << endl;
	}else{
		int L = -1;
		for(int i = 0; i < n; i++){
			int cnt = 0;
			for(int j = i; j < n; j++){
				i = n;
				cnt += (s[j] == '(' ? 1 : -1);
				if(cnt < 0 && L == -1){
					L = j;
				}else if(cnt == 0 && L != -1){
					i = j;
					ans += j - L + 1;
					L = -1;
					break;
				}
			}
		}
		cout << ans << endl;
	}
}