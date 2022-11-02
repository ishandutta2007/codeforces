#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long

char s[200001], t[200001];
int32_t main(){
	int a, b, k;
	cin >> a >> b >> k;
	
	int n = a + b;
	
	if(k >= a + b - 1 && a + b != 1){
		cout << "No" << endl;
		return 0;
	}
	
	if((a == 0 || b == 1) && k != 0){
		cout << "No" << endl;
		return 0;
	}
	
	for(int i = 0; i < b; i++){
		s[i] = t[i] = '1';
	}
	for(int i = b; i < a + b; i++){
		s[i] = t[i] = '0';
	}
	
	if(k != 0){
		swap(s[1], s[a + b - 1 - k]);
		swap(t[1], t[a + b - 1 - k]);
		swap(t[a + b - 1 - k], t[a + b - 1]);
	}
	
	cout << "Yes" << endl;
	for(int i = 0; i < n; i++){
		cout << s[i];
	}
	cout << endl;
	for(int i = 0; i < n; i++){
		cout << t[i];
	}
	cout << endl;
}