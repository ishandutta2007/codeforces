#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

typedef pair<int,int> pii;
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
	fastIO;
	string t;
	cin >> t;
	string a;
	for(int i = 0 ;i < 5; i ++ ){
		cin >> a;
		if(a[0] == t[0] || a[1] == t[1]){
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}