#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define fi first
#define se second

#define p 1000000007

using namespace std;

typedef long long ll;

int A[100000];
int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> A[i];
	}
	ll ans = 0;
	
	bool zero = false;
	int neg = 0;
	for(int i=0;i<n;i++){
		if(A[i] == 0){
			zero = 1;
			ans++;
		}
		if(A[i] < 0){
			ans += abs(-1 - A[i]); 
			neg++;
		}else if(A[i] > 0){
			ans += abs(1 - A[i]);
		}
	}
	if(neg % 2 == 1 && !zero){
		cout << ans + 2;
	}else{
		cout << ans;
	}
	return 0;
}