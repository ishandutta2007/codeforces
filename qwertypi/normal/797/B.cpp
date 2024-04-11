#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <set>
#include <algorithm>
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define fi first
#define se second
#define p1 1000000007
 
using namespace std;
typedef long long ll;

int A[100000];
int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> A[i];
	}
	sort(A, A+n);
	int pos = lower_bound(A, A+n, 0) - A;
	int ans = 0;
	for(int i=pos;i<n;i++){
		ans += A[i];
	}
	if(ans % 2){
		cout << ans;
	}else{
		int _max = 1 << 30, _min = 1 << 30;
		for(int i=pos;i<n;i++){
			if(A[i] % 2){
				_max = A[i];
				break;
			}
		}
		for(int i=pos-1;i>=0;i--){
			if(A[i] % 2){
				_min = abs(A[i]);
				break;
			}
		}
		cout << ans - min(_max, _min);
	}
	return 0;
}