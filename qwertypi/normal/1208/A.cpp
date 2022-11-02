#include <iostream>
#include <vector>
#include <utility>

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

int main(){
	int t;
	cin >> t;
	while(t--){
		int a, b, n;
		cin >> a >> b >> n;
		int c = a^b;
		switch(n % 3){
			case 0:
				cout << a << endl;
				break;
			case 1:
				cout << b << endl;
				break;
			case 2:
				cout << c << endl;
				break;
		}
	}
	return 0;
}