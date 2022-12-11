#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int main() {
	
	int n,m;
	cin >> n >> m;
	string a,b;
	cin >> a >> b;
	string sub;
	vector<int>c,cur;
	for(int i = 0;i<10000;i++){
		c.pb(1);
	}
	for(int i = 0;i<=b.size() - a.size();i++){
		sub = b.substr(i,a.size());
		for(int x = 0;x<a.size();x++){
			if(a[x] != sub[x]){
				cur.pb(x + 1);
			}
		}
		if(c.size() >= cur.size()){
			c = cur;
		}
		cur.clear();
	}
	cout << c.size() << "\n";
	for(int y = 0;y<c.size();y++){
		cout << c[y] << " "; 
	}
	return 0;
}