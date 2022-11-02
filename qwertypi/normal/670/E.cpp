#include <bits/stdc++.h>

using namespace std;

int l[500002], r[500002];
vector<int> p;
int pa[500002];
int main(){
	int n, m, pos;
	cin >> n >> m >> pos;
	l[0] = 0; r[0] = 1; l[n + 1] = n; r[n + 1] = n + 1;
	for(int i = 1; i <= n; i++){
		l[i] = i - 1;
		r[i] = i + 1;
	}
	string s, t;
	cin >> s >> t;
	for(int i = 0; i < n; i++){
		if(s[i] == '(') p.push_back(i);
		else pa[i + 1] = p.back() + 1, pa[p.back() + 1] = i + 1, p.pop_back();
	}
	for(auto i : t){
		switch(i){
			case 'L':
				pos = l[pos];
				pos = max(pos, 1);
				break;
			case 'R':
				pos = r[pos];
				pos = min(pos, n);
				break;
			case 'D':
				int st = min(pos, pa[pos]), en = max(pos, pa[pos]);
				if(l[st] == 0 && r[en] == n + 1) break;
				for(int i = st; i <= en; i = r[i]){
					l[r[i]] = l[i], r[l[i]] = r[i];
				}
				pos = r[en] == n + 1 ? l[st] : r[en];
				break;
		}
	}
	/*
	for(int i = 0; i <= n + 1; i++){
		cout << l[i] << ' ';
	}
	cout << endl;
	for(int i = 0; i <= n + 1; i++){
		cout << r[i] << ' ';
	}
	cout << endl;
	*/
	for(int i = r[0]; i <= n; i = r[i]){
		cout << s[i - 1];
	}
	cout << endl;
}