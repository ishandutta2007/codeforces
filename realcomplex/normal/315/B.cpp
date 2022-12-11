#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 123456;
ll arr[N];
int main(){
	int n,m;
	cin >> n >> m;
	for(int j = 1;j<=n;j++)cin >> arr[j];
	int t;
	int inx;
	ll d;
	ll sum = 0;
	for(int j = 0;j<m;j++){
		cin >> t;
		if(t==1){
			cin >> inx >> d;
			arr[inx] = d-sum;
		}
		else if(t==2){
			cin >> d;
			sum += d;
		}
		else{
			cin >> inx;
			cout << arr[inx]+sum << "\n";
		}
	}
	return 0;
}