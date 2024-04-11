#include <iostream>
#include <vector>
#include <utility>
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

int A[200001];
int main(){
	int b, g, n;
	cin >> b >> g >> n;
	int ans = 0;
	for(int i=0;i<=n;i++){
		if(b >= i && g >= n - i){
			ans++;
		}
	}
	cout << ans;
	return 0;
}