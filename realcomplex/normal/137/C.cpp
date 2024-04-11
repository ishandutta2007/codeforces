#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair

int main(){
	int n;
	cin >> n;
	vector<pair<int,int>>eve;
	int a,b;	
	for(int j = 0;j<n;j++){
		cin >> a >> b;
		eve.push_back(mp(a,b));
	}
	sort(eve.begin(),eve.end());
	int ans = 0;
	int lb = 0;
	for(int x = 0;x<eve.size();x++){
		if(eve[x].fi<lb&&eve[x].se<lb)ans++;
		else{
			lb = eve[x].se;
		}
	}
	cout << ans;
	return 0;
}