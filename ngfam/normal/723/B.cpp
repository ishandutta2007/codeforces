#include <bits/stdc++.h>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("0.inp", "r", stdin);
		freopen("0.out", "w", stdout);	
	#endif

	bool inside = 0; 
	int n; cin >> n;
	string a;

	cin >> a;
	
	int cur = 0, ans = 0, curcnt = 0, anscnt = 0;
	
	for(int i = 0; i < a.size(); ++i){
		if((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z')){
			cur = cur + 1;
			if(cur == 1){
				if(inside){
			//		cout << a[i] << endl;	
				}
				if(inside == 1) ++curcnt;
			}
			if(inside == 0) ans = max(ans, cur);
		}
		else{
			if(a[i] == '('){
				inside = true;
			}	
			if(a[i] == ')'){
				anscnt += curcnt;
				curcnt = 0;
				inside = 0;
			}
			cur = 0;
		}       
	}
	cout << ans << " " << anscnt << endl;
}