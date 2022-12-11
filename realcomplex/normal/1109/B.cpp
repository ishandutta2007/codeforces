#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef pair<ll, ll> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

bool is_palindrome(string a){
	int n = a.size();
	for(int i = 0 ;i < n/2;  i ++ ){
		if(a[i] != a[n - i - 1])
			return false;
	}
	return true;
}

int main(){
	fastIO;
	string s;
	cin >> s;
	int n = s.size();
	string a, b;
	for(int i = 0 ; i < (int)s.size(); i ++ ){
		a.push_back(s[i]);
		b.clear();
		for(int j = i + 1; j < s.size(); j ++ )
			b.push_back(s[j]);
			
		if(is_palindrome(b + a) && string(b + a) != s){
			cout << 1;
			return 0;
		}
	}
	a.clear();
	b.clear();
	for(int i = 0 ; i < n/2; i ++ ){
		a.push_back(s[i]);
		b = s[n - i - 1] + b;
		if(a != b){
			cout << 2;
			return 0;
		}
	}
	cout << "Impossible";
	return 0;
}