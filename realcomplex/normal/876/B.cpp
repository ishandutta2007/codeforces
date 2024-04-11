#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
vector<int>mod[MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,k,m;
	cin >> n >> k >> m;
	int sk;
	for(int j = 0;j<n;j++){
		cin >> sk;
		mod[sk%m].push_back(sk);
	}
	for(int i = 0;i<MAXN;i++){
		if(mod[i].size() >= k){
			cout << "Yes\n";
			for(int x = 0;x<k;x++) cout << mod[i][x] << " ";
			exit(0);
		}
	}
	cout << "No";
	return 0;
}