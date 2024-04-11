//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

vector<int> vec;

bool isprime(int x){
	for(int i = 2; i * i <= x; i++)
		if(x % i == 0)
			return false;
	return true;
}

int main(){
	for(int i = 2; i <= 50; i++){
		if(isprime(i)){
			cout << i << '\n';
			fflush(stdout);
			string s;
			cin >> s;
			if(s == "yes")
				vec.PB(i);
			if(sz(vec) > 1){
				cout << "composite" << endl;
				fflush(stdout);
				return 0;
			}
		}
	}
	if(sz(vec) == 0 or vec[0] * vec[0] > 100){
		cout << "prime" << endl;
		fflush(stdout);
		return 0;
	}
	cout << vec[0] * vec[0] << '\n';
	fflush(stdout);
	string s;
	cin >> s;
	if(s == "yes")
		cout << "composite\n";
	else
		cout << "prime\n";
	fflush(stdout);
	return 0;
}