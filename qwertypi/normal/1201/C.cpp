#include <iostream>
#include <string>
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
 
int A[200000];
int diff[100000];
int main(){
	int n, k;
	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> A[i];
	}
	sort(A, A+n);
	int mid = n / 2;
	for(int i=mid;i<n-1;i++){
		diff[i-mid] = A[i+1] - A[i];
	}
	int ans = A[mid];
	for(int i=0;i<mid;i++){
		if(k >= (long long)diff[i] * (i + 1)){
			k -= diff[i] * (i + 1);
			ans += diff[i];
		}else{
			ans += k / (i + 1);
			k = 0;
			break;
		}
	}
	ans += k / (mid + 1);
	cout << ans;
	return 0;
}