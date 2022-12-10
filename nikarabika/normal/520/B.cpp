#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e4 + 10;
int h[maxn];

int main(){
	for(int i = 0; i < maxn; i++)
		h[i] = -1;
	int n, m;
	cin >> n >> m;
	queue<int> Q;
	Q.push(n);
	h[n] = 0;
	while(Q.size()){
		int x = Q.front();
		Q.pop();
		if(x == m){
			cout << h[x] << endl;
			return 0;
		}
		if(2 * x < maxn and !(h[2 * x] + 1))
			h[2 * x] = h[x] + 1, Q.push(2 * x);
		if(x > 1 and !(h[x - 1] + 1))
			h[x - 1] = h[x] + 1, Q.push(x - 1);
	}
	return 0;
}