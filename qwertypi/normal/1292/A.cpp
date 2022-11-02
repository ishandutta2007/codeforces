#include <bits/stdc++.h>
#pragma optimize("O2")
#define int long long
#define IOS cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false)
using namespace std;
typedef long long ll;

set<pair<int, int>> A;
int32_t main(){
	IOS;
	int n, q;
	cin >> n >> q;
	int block = 0;
	for(int i = 0; i < q; i++){
		int x, y;
		cin >> x >> y;
		if(A.find({x, y}) == A.end()){
			A.insert({x, y});
			if(A.find({3 - x, y - 1}) != A.end()){
				block++;
			}
			if(A.find({3 - x, y}) != A.end()){
				block++;
			}
			if(A.find({3 - x, y + 1}) != A.end()){
				block++;
			}
		}else{
			A.erase({x, y});
			if(A.find({3 - x, y - 1}) != A.end()){
				block--;
			}
			if(A.find({3 - x, y}) != A.end()){
				block--;
			}
			if(A.find({3 - x, y + 1}) != A.end()){
				block--;
			}
		}
		if(block == 0){
			cout << "Yes" << endl;
		}else{
			cout << "No" << endl;
		}
	}
	return 0;
}