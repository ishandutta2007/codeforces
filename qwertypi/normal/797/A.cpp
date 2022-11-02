#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <set>
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
int main(){
	int n, k;
	cin >> n >> k;
	vector<int> pf;
	for(int i = 2; i * i <= n; i++){
		while(n % i == 0){
			n /= i;
			pf.push_back(i);
		}
	}
	if(n != 1){
		pf.push_back(n);
	}
	if(pf.size() < k){
		cout << -1;
	}else{
		for(int i=0;i<k-1;i++){
			cout << pf[i] << ' ';
		}
		int last = 1;
		for(int i=k-1;i<pf.size();i++){
			last *= pf[i];
		}
		cout << last;
	}
	return 0;
}