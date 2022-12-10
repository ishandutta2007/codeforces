#include <bits/stdc++.h>

using namespace std;

set<int> s;
int n, k, a, m;

int f(int l, int r){
	return (r - l) / (a + 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//while(cin >> n >> k)
		//cout << f(n, k) << endl;
	cin >> n >> k >> a;
	cin >> m;
	s.insert(0);
	s.insert(n + 1);
	int ready = f(0, n + 1);
	for(int i = 1; i <= m; i++){
		int pos;
		cin >> pos;
		auto it = s.lower_bound(pos);
		int jolo = *it;
		it--;
		int back = *it;
		ready -= f(back, jolo);
		ready += f(back, pos) + f(pos, jolo);
		if(ready < k){
			cout << i << endl;
			return 0;
		}
		s.insert(pos);
	}
	cout << -1 << endl;
	return 0;
}