#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef pair<ll, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
	fastIO;
	string t;
	cin >> t;
	int c1 = 0, c2 = 0;
	for(char x : t){
		if(x == '0'){
			cout << 1 << " " << c1 + 1 << "\n";
			c1 ++  ;
			c1 %= 4; 
		}
		else{
			cout << 3 << " " <<  c2 * 2 + 1 << "\n";
			c2 ++ ;
			c2 %= 2;
		}
	}
	return 0;
}