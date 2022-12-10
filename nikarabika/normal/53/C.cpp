#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int turn = 1;
	int p1 = 1, p2 = n;
	while(p1 <= p2 and ++turn)
		if(turn & 1) cout << p2-- << ' ';
		else cout << p1++ << ' ';
	cout << endl;
	return 0;
}