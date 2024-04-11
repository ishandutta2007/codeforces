#include <bits/stdc++.h>
#define int long long
// !!!!!!!!!!!
// Last Div 2!
// Hope so.
// !!!!!!!!!!!
 
 
using namespace std;
 
void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	char _p = ' ';
	int st = 0;
	int ans1 = 0, ans2 = -1;
	for(int i = 1; i < n; i++){
		// cout << s[i - 1] << ' ' << s[i] << endl;
		if(s[i - 1] == ' ') continue;
		if(s[i] == ' ') continue;
	    if(s[i] == s[i - 1] && s[i] != ' '){
	        s[i - 1] = s[i] = ' ';
	        ans1++;
	        ans2 = i;
	        continue;
	    }else if(s[i - 1] == '(' && s[i] == ')'){
	        s[i - 1] = s[i] = ' ';
	        ans1++;
	        ans2 = i;
	        continue;
	    }else{
	        bool okay = false;
	        for(int j = i; j < n; j++){
	            if(s[j] == ')'){
	                for(int k = i - 1; k <= j; k++){
	                    s[k] = ' ';
	                }
                    ans1++;
                    ans2 = j;
                    okay = true;
                    break;
	            }
	            if(okay) break;
	        }
	        if(!okay){
	        	cout << ans1 << ' ' << n - 1 - ans2 << endl;
	        	return;
			}
	    }
	}
	cout << ans1 << ' ' << n - 1 - ans2 << endl;
}
 
int32_t main(){
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
}