#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll ;
typedef double db;
typedef pair<int, int> pii;
 
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
	fastIO;
	string t;
	cin >> t;
	int k;
	cin >> k;
	int n = t.size();
	int canes = 0; // '?'
	int flakes = 0; // '*'
	for(int i = 0 ;i < t.size(); i ++ ){
		if(t[i] == '?')
			canes ++ ;
		else if(t[i] == '*')
			flakes ++ ;
	}
	if(flakes == 0){
		bool use[n];
		int sz = n;
		for(int i = 0 ;i < n; i ++ )
			use[i] = true;
		for(int i = 0 ; i < n; i ++ ){
			if(t[i] == '?'){
				sz -- ;
				use[i] = false;
			}
		}
		for(int i = 0 ;i < n; i ++ ){
			if(t[i] == '?'){
				if(sz > k){
					sz -- ;
					use[i - 1] = false;
				}
			}
		}
		if(sz == k){
			for(int i = 0 ; i < n ; i ++ )
				if(use[i])
					cout << t[i];
		}
		else{
			cout << "Impossible\n";
			return 0;
		}
	}
	else{
		if(n - canes * 2 - flakes * 2 <= k){
			bool use[n];
			int sz = n;
			int idx = -1;
			for(int i = 0 ;i < n; i ++ ){
				use[i] = true;
			}
			for(int i = 0 ;i < n ; i ++ ){
				if(t[i] == '?'){
					use[i - 1] = false;
					use[i] = false;
					sz -= 2;
				}
				else if(t[i] == '*'){
					use[i] = false;
					use[i - 1] = false;
					if(idx == -1)
						idx = i - 1;
					sz -= 2;
				}
			}
			for(int i = 0 ; i < n; i ++ ){
				if(i == idx){
					while(sz != k){
						cout << t[i];
						sz ++ ;
					}
				}
				else{
					if(use[i])
						cout << t[i];
				}
			}
		}
		else{
			cout << "Impossible\n";
			return 0;
		}
	}
	return 0;
}