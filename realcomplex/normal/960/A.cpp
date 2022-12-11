#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))

int main(){
	fastIO;
	string s;
	cin >> s;
	int a = 0,b = 0,c = 0;
	int cur = 0;
	for(auto x : s){
		if(x == 'a'){
			if(cur > 0){
				cout << "NO";
				return 0;
			}
			a++;
			cur = 0;
		}
		else if(x == 'b'){
			if(cur > 1){
				cout << "NO\n";
				return 0;
			}
			b++;
			cur = 1;
		}
		else{
			if(cur > 2){
				cout << "NO\n";
				return 0;
			}
			c++;
			cur = 2;
		}
	}
	if((c != a and c != b ) or (a == 0 or b == 0 or c == 0)){
		cout << "NO";
	}
	else{
		cout << "YES";
	}
	return 0;
}