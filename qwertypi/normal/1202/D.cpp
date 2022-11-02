#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>

#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define fi first
#define se second

#define p 1000000007

typedef long long ll;

using namespace std;
ll prec[100000];
void query(ll n){
	int b = upper_bound(prec, prec+100000, (ll)n) - prec;
	n -= prec[b - 1];
	vector<int> pos;
	while(n != 0){
		int b1 = upper_bound(prec, prec+100000, (ll)n) - prec;
		pos.push_back(b1);
		n -= prec[b1 - 1];
	}
	string s;
	for(int i=0;i<b;i++){
		s.push_back('3');
	}
	for(auto i:pos){
		s.insert(i, "7");
	}
	s.insert(0, "1");
	s.push_back('7');
	cout << s << endl;
}


int main(){
	for(int i=0;i<100000;i++){
		prec[i] = (ll)i * (i + 1) / 2;
	}
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		ll x;
		cin >> x;
		query(x); 
	}
	return 0;
}