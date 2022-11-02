#include <iostream>
#include <vector>
#include <utility>
#include <map>

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
typedef long double ld;

int A[2000];
map<int, int> M;
int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> A[i];
		M[A[i]]++;
	}
	int left = 0;
	for(auto i: M){
		left += i.se - 1;
	}
	int L = 0;
	int R = -1;
	int ans = (1 << 30);
	while(R < n){
		if(left == 0){
			ans = min(ans, R - L + 1);
			M[A[L]]++;
			if(M[A[L]] >= 2){
				left++;
			}
			L++;
			if(R < L){
				R++;
			}
		}else{
			R++;
			M[A[R]]--;
			if(M[A[R]] >= 1){
				left--;
			}
		}
	}
	if(left == 0){
		ans = min(ans, R-L+1);
	}
	cout << ans;
	return 0;
}