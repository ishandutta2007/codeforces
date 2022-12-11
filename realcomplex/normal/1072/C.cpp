#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin(),(x).end())
#define len(x) ((ll)(x).size())

int main(){
	fastIO;
	int a, b;
	cin >> a >> b;
	vector<int> al;
	vector<int> v1, v2;
	int n = a + b;
	int p = 1;
	while(n >= p){
		n -= p;
		al.push_back(p);
		p ++;
	}
	for(int j = al.size() - 1; j >= 0 ; j -- ){
		if(a >= al[j]){
			a -= al[j];
			v1.push_back(al[j]);
		}
		else{
			b -= al[j];
			v2.push_back(al[j]);
		}
	}
	cout << v1.size() << "\n";;
	for(auto x : v1)
		cout << x  << " ";
	cout << "\n" ;
	cout << v2.size() <<"\n";
	for(auto x : v2)
		cout <<x << " ";
	return 0;
}