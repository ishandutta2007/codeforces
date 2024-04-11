#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define fi first
#define se second

using namespace std;

typedef long long ll;

int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << ((i + j) % 2 ? 'B' : 'W'); 
		}
		cout << endl;
	}
	return 0;
}