#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e2 + 85 - 69;
string s;
int n, num = 0;

void make(int r = 0, int p = 0){
	if(r > 3)
		return;
	if(p == n){
		if(r == 0)
			return;
		if(num % 8 == 0){
			cout << "YES" << endl;
			cout << num << endl;
			exit(0);
		}
		return;
	}
	make(r, p + 1);
	num = num * 10 + int(s[p] - '0');
	make(r + 1, p + 1);
	num /= 10;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> s;
	n = s.size();
	make();
	cout << "NO" << endl;
	return 0;
}