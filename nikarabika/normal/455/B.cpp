#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
int n, bib;
string s[maxn];

bool win(int k = 0, int b = 0, int e = n){
	while(b < e and s[b].size() == k) b++;
	if(e - b == 0)
		return 0;
	if(e - b == 1){
		if((s[b].size() - k) % 2)
			return 1;
		return 0;
	}
	int p, q;
	for(int i = b; i < e; i = q){
		p = i, q = i;
		while(s[q][k] == s[p][k])
			q++;
		if(!win(k + 1, p, q))
			return 1;
	}
	return 0;
}

bool lose(int k = 0, int b = 0, int e = n){
	while(b < e and s[b].size() == k) b++;
	if(e - b == 0)
		return 1;
	if(e - b == 1){
		if((s[b].size() - k) % 2)
			return 0;
		return 1;
	}
	int p, q;
	for(int i = b; i < e; i = q){
		p = i, q = i;
		while(s[q][k] == s[p][k])
			q++;
		if(!lose(k + 1, p, q))
			return 1;
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> bib;
	for(int i = 0; i < n; i++)
		cin >> s[i];
	sort(s, s + n);
	bool x = win(), y = lose();
	if(!x)
		cout << "Second" << endl;
	else if(lose())
		cout << "First" << endl;
	else
		cout << ((bib & 1) ? "First" : "Second") << endl;
	return 0;
}