#include <bits/stdc++.h>

using namespace std;

int k, p;

void make(int s){
	for(int i = 1; i <= 2 * k; i++)
		cout << s << ' ' << i + s << '\n';
	for(int i = 1; i <= 2 * k; i++)
		for(int j = 2 * k + 1; j <= 4 * k; j++)
			cout << s + i << ' ' << s + j << '\n';
	for(int i = 2 * k + 1; i <= 4 * k; i += 2)
		cout << s + i << ' ' << s + i + 1 << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> p;
	if(p % 2 == 0){
		cout << "NO" << endl;
		return 0;
	}
	k = p / 2;
	cout << "YES" << endl;
	cout << 8 * k + 2 << ' ' << 2 * (3 * k + 4 * k * k) + 1 << '\n';
	cout << 1 << ' ' << 4 * k + 2 << '\n';
	make(1);
	make(4 * k + 2);
	return 0;
}