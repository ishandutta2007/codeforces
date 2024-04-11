#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))

int main(){
	int a,b;
	cin >> a >>b;
	vector<int>D;
	D.push_back(b);
	while(b > a){
		if(b % 2 == 0){
			b /= 2;
			D.push_back(b);
		}
		else if(b % 10 == 1){
			b /= 10;
			D.push_back(b);
		}
		else{
			cout << "NO\n";
			return 0;	
		}
	}
	if(a!=b){
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	cout << D.size() << "\n";
	reverse(D.begin(),D.end());
	for(auto x : D)
		cout << x << " ";
	return 0;
}