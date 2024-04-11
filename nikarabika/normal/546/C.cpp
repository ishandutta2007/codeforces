#include <bits/stdc++.h>

using namespace std;

int n, k1, k2;
queue<int> Q1, Q2;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	int fact = 10;
	for(int i = 1; i <= n; i++)
		fact *= i;
	cin >> k1;
	for(int i = 0; i < k1; i++){
		int x;
		cin >> x;
		Q1.push(x);
	}
	cin >> k2;
	for(int i = 0; i < k2; i++){
		int x;
		cin >> x;
		Q2.push(x);
	}
	for(int i = 0; i < fact + 5; i++){
		if(Q1.size() == 0){
			cout << i << ' ' << 2 << endl;
			return 0;
		}
		if(Q2.size() == 0){
			cout << i << ' ' << 1 << endl;
			return 0;
		}
		if(Q1.front() > Q2.front()){
			Q1.push(Q2.front());
			Q1.push(Q1.front());
			Q1.pop();
			Q2.pop();
		}
		else if(Q1.front() < Q2.front()){
			Q2.push(Q1.front());
			Q2.push(Q2.front());
			Q1.pop();
			Q2.pop();
		}
	}
	cout << -1 << endl;
	return 0;
}