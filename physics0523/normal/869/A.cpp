#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> x(n),y(n);
	vector<int> mem(2222222,0);
	for(auto &nx : x){cin >> nx;mem[nx]++;}
	for(auto &nx : y){cin >> nx;mem[nx]++;}
	int res=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			res+=mem[x[i]^y[j]];
		}
	}
	if(res%2==0){cout << "Karen\n";}
	else{cout << "Koyomi\n";}
  return 0;
}