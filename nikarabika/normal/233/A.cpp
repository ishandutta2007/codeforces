#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n; cin >> n; if(n & 1){ cout << -1 << endl; return 0;} for(int i = 0; i < n; i++) cout << (i ^ 1) + 1 << ' '; cout << endl;
	return 0;
}