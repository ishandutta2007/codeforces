#include <bits/stdc++.h>
#define int long long
#define m 1000000007
using namespace std;

void sub(){
	int n;
	string s;
	cin >> n >> s;
	int pos = 0;
	int len = 0;
	len = s.size();
	while(len < n){
		int t = s[pos] - '0';
		for(int i = 0; i < (t - 1) * (len - pos - 1) && s.size() < n; i++){
			s.push_back(s[i % (len - pos - 1) + pos + 1]);
		}
		len = (len - pos - 1) * t + pos + 1;
		pos++;
	}
	for(int i = pos; i < n; i++){
		int t = s[i] - '0';
		len = (len - i - 1 + m) % m * t + i + 1;
		len %= m;
	}
	cout << len << endl;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}