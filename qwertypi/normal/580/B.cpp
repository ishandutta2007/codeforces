#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<pair<int, int>> friends; // money, friendship factor

int L_base(pair<int, int> A, pair<int, int> B){
	return A.first < B.first;
}

long long prec[100001];
int main(){
	int n, k;
	cin >> n >> k;
	friends.resize(n);
	for(int i=0;i<n;i++){
		int m, f;
		cin >> m >> f;
		friends[i] = make_pair(m, f);
	}
	sort(friends.begin(), friends.end(), L_base);
	prec[0] = 0;
	for(int i=0;i<n;i++){
		prec[i+1] = prec[i] + friends[i].second; 
	}
	int L = 0;
	int R = 0;
	long long ans = 0;
	while(R < n){
		if(friends[R].first - friends[L].first < k){
			ans = max(ans, prec[R+1] - prec[L]);
			R++;
		}else{
			L++;
		}
	}
	cout << ans;
}