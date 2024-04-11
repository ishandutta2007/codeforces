#include <bits/stdc++.h>
 
using namespace std;

string t1, t2;

vector<int> pre;
int g(string const& s, int n){
	pre.resize(max((int)pre.size(), n));
	pre[0] = 0;
	for(int i = 1; i < n; i++){
		int g = i;
		while(g != 0){
			if(s[pre[g-1]] == s[i]){
				pre[i] = pre[g-1] + 1;
				break;
			}else{
				pre[i] = 0;
				g = pre[g-1];
			}
		}
	}
	return pre[n - 1];
}

string s;

pair<int, int> f(int L, int R){
	t1.resize(max((int)t1.size(), (R - L + 1) * 2 + 1));
	t2.resize(max((int)t2.size(), (R - L + 1) * 2 + 1));
	
	for(int i = 0; i <= R - L; i++){
		t1[i] = s[L + i];
	}
	t1[R - L + 1] = '|';
	for(int i = 0; i <= R - L; i++){
		t1[(R - L + 1) * 2 - i] = s[L + i];
	}
	
	for(int i = 0; i <= R - L; i++){
		t2[i] = s[R - i];
	}
	t2[R - L + 1] = '|';
	for(int i = 0; i <= R - L; i++){
		t2[(R - L + 1) * 2 - i] = s[R - i];
	}
	
	return {L + g(t1, (R - L + 1) * 2 + 1), R - g(t2, (R - L + 1) * 2 + 1)};
}
 
void f(int n){
	int L = 0, R = n - 1;
	while(s[L] == s[R] && L < R){
		L++, R--;
	}
	
	if(L > R){
		cout << s << endl;
		return;
	}
	
	pair<int, int> x = f(L, R);
	int fL = x.first, fR = x.second;
	
	if(fL - L > R - fR){
		for(int i = 0; i < fL; i++){
			cout << s[i];
		}
		
		for(int i = R + 1; i < n; i++){
			cout << s[i];
		}
		
	}else{
 
		for(int i = 0; i < L; i++){
			cout << s[i];
		}
		
		for(int i = fR + 1; i < n; i++){
			cout << s[i];
		}
		
	}
	cout << endl;
}
 
int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> s;
		f(s.size());
	}
}