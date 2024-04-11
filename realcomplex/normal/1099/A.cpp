#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll ;
typedef double db;
typedef pair<int, int> pii;
 
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int stone[105];

int main(){
	fastIO;
	int ws, hs;
	cin >> ws >> hs;
	int w, h;
	for(int j = 0 ;j  < 2; j ++ ){
		cin >> w >> h;
		stone[h] = w;
	}
	for(int i = hs ; i >= 0 ; i -- ){
		ws += i;
		ws -= stone[i];
		ws = max(ws, 0);
	}
	cout << ws;
	return 0;
}