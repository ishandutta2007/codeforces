#include <bits/stdc++.h>
 
#define int long long
using namespace std;
 
int powmod(int a, int b, int p){
	int res = 1;
	while(b){
		if(b % 2){
			res = (res * a) % p;
		}
		b /= 2;
		a = (a * a) % p;
	}
	return res;
}

bool A[10];
void sub(){
	string s, t;
	cin >> s >> t;
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());
	int n = s.size(), m = t.size();
	int j = 0;
	for(int i = 0; i < n;){
		if(j == m){
			cout << "YES" << endl;
			return;
		}
		if(s[i] == t[j]){
			j++;
			i++;
		}else{
			i += 2;
		}
	}
	if(j == m){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
	
}


int32_t main(){
	int J;
	cin >> J;
	while(J--){
		sub();
	}
}