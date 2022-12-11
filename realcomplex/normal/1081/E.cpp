#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll ;
typedef double db;
typedef pair<int, int> pii;
 
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;

vector<int> divs[N];

ll x[N];

void NO(){
	cout << "No\n";
	exit(0);
}

int main(){
	fastIO;
	for(int i = 1; i < N; i ++ ){
		for(int j = i; j < N ; j += i){
			divs[j].push_back(i);
		}
	}
	int n;
	cin >> n;
	for(int i = 1; i <= n/2; i ++ ){
		cin >> x[2 * i];
	}
	ll v1, v2;
	ll A, B;
	ll ps = 0;
	ll sol;
	ll sum = 0;
	for(int z = 1; z <= n; z += 2 ){
		sol = -1;
		for(auto p : divs[x[z + 1]]){
			v1 = p; // x - y
			v2 = x[z + 1] / p; // x + y
			if(v1 < v2)
				swap(v1, v2);
			
			if((v1 + v2) % 2 != (v1 - v2) % 2 ){
				continue;
			}
			A = (v1 + v2)/2;
			B = (v1 - v2)/2;
			A *= A;
			B *= B;
			if(A - sum - x[z + 1] == B - sum && B - sum > 0){
				if(sol == -1 || B - sum < sol){
					sol = B - sum;
				}
			}
		}
		if(sol <= 0)
			NO();
		x[z] = sol;
		sum += sol;
		sum += x[z + 1];
	}
	cout << "Yes\n";
	for(int i = 1; i <= n; i ++ ){
		cout << x[i] << " "; 
	}
	return 0;
}