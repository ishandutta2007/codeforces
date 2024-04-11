#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <deque>
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

char A[1000001];
int n, m;

char temp[1000000];

bool OK[1000000];
bool OK2[1000000];
int main(){
	cin >> n >> m;
	fill(OK, OK+n*m, 0);
	fill(OK2, OK2+n*m, 0);
	for(int i=0;i<n;i++){
		cin >> temp;
		for(int j=0;j<m;j++){
			A[i * m + j] = temp[j];
		}
	}
	A[n * m] = '\0';
	OK[0] = 1;
	OK2[n * m - 1] = 1;
	for(int sum = 1; sum < n + m - 2; sum++){
		for(int i = max(0, sum - m + 1); i <= min(n-1, sum); i++){
			int op = i * m + sum - i;
			if(A[op] == '#'){
				continue;
			}
			if(i != 0){
				OK[op] = max(OK[op], OK[op - m]);
			}
			if(sum - i != 0){
				OK[op] = max(OK[op], OK[op - 1]);
			}
		}
	}
	for(int sum = n + m - 3; sum >= 1; sum--){
		for(int i = min(n-1, sum); i >= max(0, sum - m + 1); i--){
			int op = i * m + sum - i;
			if(A[op] == '#' || !OK[op]){
				continue;
			}
			if(i != n - 1){
				OK2[op] = max(OK2[op], OK2[op + m]);
			}
			if(sum - i != m - 1){
				OK2[op] = max(OK2[op], OK2[op + 1]);
			}
		}
	}
	int ans = 2;
	for(int sum = 1; sum < n + m - 2; sum++){
		int cnt = 0;
		for(int i = max(0, sum - m + 1); i <= min(n-1, sum); i++){
			int op = i * m + sum - i;
			cnt += OK2[op];
		}
		ans = min(ans, cnt);
	}
	cout << ans;
	return 0;
}