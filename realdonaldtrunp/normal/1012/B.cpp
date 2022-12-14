#include<bits/stdc++.h>
using namespace std;


int n;
int m;
int q;

vector<int> x[200002];
vector<int> y[200002];

struct U_F{
	vector<int> belong;
	void resize(int n){
		belong.assign(n + 1, -1);
	}
	int root(int b){
		if (belong[b] == -1){
			return b;
		}
		return belong[b] = root(belong[b]);
	}
	void merge(int a, int b){
		a = root(a);
		b = root(b);
		if (a != b){
			belong[a] = b;
		}
	}
};
U_F ufx;
set<int> xx;
set<int> yy;
int main(){
	cin >> n >> m >> q;
	ufx.resize(m+n);
	for (int i = 0; i < q; i++){
		int r, c;
		scanf("%d%d", &r, &c);
		r--;
		c--;
		ufx.merge(c, r + m);
		xx.insert(r);
		yy.insert(c);
		x[r].push_back(c);
		y[c].push_back(r);
	}
	int ans = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < x[i].size(); j++){
			ufx.merge(x[i][0], x[i][j]);
		}
	}
	for (int i = 0; i < m; i++){
		for (int j = 0; j < y[i].size(); j++){
			ufx.merge(y[i][0]+m, y[i][j]+m);
		}
	}
	/*int nx = 0;
	int ny = 0;
	for (int i = 0; i < n; i++){
		if (xx.count(i) == 0)nx++;
	}
	for (int i = 0; i < m; i++){
		if (yy.count(i) == 0)ny++;
	}*/
	int pap = 0;
	for (int i = 0; i < n+m; i++){
		if (ufx.root(i) == i)pap++;
	}
	/*for (int j = 0; j < n; j++){
		if (ufy.root(j) == j)pap++;
	}*/
	pap--;
	cout << pap<< endl;
	return 0;
}