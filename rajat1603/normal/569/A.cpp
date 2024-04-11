#include "bits/stdc++.h"
using namespace std;
int t , s , q , ans = 0;
int main(){
	cin >> t >> s >> q;
	while(s < t){
		++ans;
		s *= q;
	}
	cout << ans;
}