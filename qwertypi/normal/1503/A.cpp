#include <bits/stdc++.h>

using namespace std;

bool check(string& s){
	int cnt = 0;
	for(auto i : s){
		cnt += (i == '(' ? +1 : -1);
		if(cnt < 0) return false;
	}
	if(cnt != 0) return false;
	return true;
}

void sub(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	string a, b;
	a.resize(n), b.resize(n);
	int cnt_1 = 0;
	for(int i = 0; i < n; i++){
		cnt_1 += s[i] == '1';
	}
	int cnt_0 = n - cnt_1;
	if(cnt_0 % 2 == 1 || n % 2 == 1){
		cout << "NO" << endl;
		return;
	}
	
	int rcnt_1 = 0, par = 0;
	int cnt_a = 0, cnt_b = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '1'){
			if(rcnt_1 + 1 <= cnt_1 / 2){
				a[i] = b[i] = '(';
			}else{
				a[i] = b[i] = ')';
			}
			rcnt_1++;
		}else{
			a[i] = (par ? '(' : ')');
			b[i] = (par ? ')' : '(');
			par = !par;
		}
	}
	
	if(!check(a) || !check(b)){
		cout << "NO" << endl;
	}else{
		cout << "YES" << endl;
		cout << a << endl;
		cout << b << endl;
	}
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}