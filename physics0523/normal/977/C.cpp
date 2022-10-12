#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
	int n,m;
	cin >> n >> m;
	vector<int> a(n);
	for(auto &nx : a){cin >> nx;}
	a.push_back(1000000007);
	sort(a.begin(),a.end());
	if(m==0){
		if(a[0]==1){cout << "-1\n";}
		else{cout << "1\n";}
		return 0;
	}
	if(a[m-1]!=a[m]){cout << a[m-1] << '\n';}
	else{cout << "-1\n";}
  return 0;
}