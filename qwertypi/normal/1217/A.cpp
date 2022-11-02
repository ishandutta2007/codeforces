#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

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
 
int main(){
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		int a, b, c;
		cin >> a >> b >> c;
		int upper = c;
		int lower = max(0, (int)floor((double)(b + c - a) / 2) + 1);
		cout << max(0, upper - lower + 1) << endl;
	}
	return 0;
}