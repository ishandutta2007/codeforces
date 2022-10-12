#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> res;
	if(n%2){n-=3;res.push_back(3);}
	while(n>0){
		n-=2;
		res.push_back(2);
	}
	cout << res.size() << '\n';
	for(int i=0;i<res.size();i++){
		if(i){cout << ' ';}
		cout << res[i];
	}cout << '\n';
  return 0;
}