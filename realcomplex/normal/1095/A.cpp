#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int main(){
	fastIO;
	int n;
	cin >> n;
	string t;
	cin >> t;
	int d = 0;
	int v = 0;
	while(d < n){
		cout << t[d];
		v ++ ;
		d += v;
	}
	return 0;
}