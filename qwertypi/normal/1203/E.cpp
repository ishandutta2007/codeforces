#include <iostream>
#include <vector>
#include <utility>
#include <random>
#include <algorithm>
#define mp make_pair
#define pb push_back 
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define fi first
#define se second

#define p 1000000007

using namespace std;
typedef long long ll;

int A[150000];
int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> A[i];
	}
	sort(A, A+n);
	int ans = 0;
	int _max = (1 << 30);
	for(int i=n-1;i>=0;i--){
		if(_max > A[i] + 1){
			_max = A[i] + 1;
			ans++;
		}else if(_max > A[i]){
			_max = A[i];
			ans++;
		}else if(_max > A[i]-1 && A[i] != 1){
			_max = A[i]-1;
			ans++;
		}
	}
	cout << ans;
	return 0;
}