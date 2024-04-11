#include <bits/stdc++.h>
using namespace std; 

class DSU {
	private:
		vector<int> Parent, Size, Next;
	public:
		DSU(int n){
			Parent.resize(n);
			Size.resize(n); 
			for (int i = 0; i < n; i++) Parent[i] = i;
			for (int i = 0; i < n; i++) Size[i] = 1;
		}
		int root(int x){
			if(x != Parent[x]) return Parent[x] = root(Parent[x]);
			return x;
		}
		
		bool join(int x, int y) {
			x = root(x);
			y = root(y);
			Parent[x] = y;
			/*
			if (x == y) return false;
			if (Size[x] < Size[y]) swap(x, y);
			Size[x] += Size[y];
			Parent[y] = x;*/
			return true;
		}
		int getSize(int x) { return Size[root(x)]; }
		
};

int ans[300001];
int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	DSU dsu(n + 2);
	for(int i = 0; i < m; i++){
		int l, r, d;
		cin >> l >> r >> d;
		for(int i = dsu.root(l); i <= r; i = dsu.root(i + 1)){
			if(i != dsu.root(d)){
				ans[i] = d;
				dsu.join(i, i + 1);
			}
		}
	}
	for(int i = 1; i <= n; i++){
		cout << ans[i] << ' ';
	}
 }