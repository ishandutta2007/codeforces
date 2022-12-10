#include <bits/stdc++.h>

using namespace std;

#define PB push_back

const int maxn = 2e5 + 85 - 75;
int n, k;
vector<int> v[maxn];
int t[maxn];
bool mark[maxn];

bool isfree(int x, int tm){
	return (x <= n) ? tm < x : tm < x - n;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	string s;
	cin >> s;
	for(int i = 1; i <= n; i++){
		if(s[i - 1] == 'X') mark[i] = true;
		if(i < n) v[i].PB(i + 1);
		if(i > 1) v[i].PB(i - 1);
		if(i <= n - k) v[i].PB(i + k + n);
		if(i > n - k) v[i].PB(2 * n + 1);
	}
	cin >> s;
	for(int i = n + 1; i <= 2 * n; i++){
		if(s[i - n - 1] == 'X') mark[i] = true;
		if(i < 2 * n) v[i].PB(i + 1);
		if(i > n + 1) v[i].PB(i - 1);
		if(i <= 2 * n - k) v[i].PB(i + k - n);
		if(i > 2 * n - k) v[i].PB(2 * n + 1);
	}
	queue<int> Q;
	mark[1]= true;
	t[1] = 0;
	Q.push(1);
	while(Q.size()){
		int x = Q.front();
		Q.pop();
		for(auto y : v[x]){
			if(!mark[y] and isfree(y, t[x] + 1)){
				if(y == 2 * n + 1){
					cout << "YES" << endl;
					return 0;
				}
				mark[y] = true;
				t[y] = t[x] + 1;
				Q.push(y);
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}