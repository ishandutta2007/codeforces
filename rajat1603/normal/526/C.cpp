#include "bits/stdc++.h"
using namespace std;
long long c , hr , hb , wr , wb , ans;
int main(){
	cin >> c >> hr >> hb >> wr >> wb;
	ans = 0;
	for(int i = 0 ; i < 2 ; ++i){
		for(int j = 0 ; j < 1e5 ; ++j){
			if(wr * j <= c){
				ans = max(ans , hr * j + ((c - wr * j) / wb) * hb);
			}
		}
		swap(hr , hb);
		swap(wr , wb);
	}
	cout << ans << endl;
}