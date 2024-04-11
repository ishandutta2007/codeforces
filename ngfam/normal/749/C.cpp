#include <bits/stdc++.h>
using namespace std;

int main(){
 	//freopen("1.inp", "r", stdin);
 	//freopen("1.out", "w", stdout);
 	int n; string s;
 	cin >> n >> s;

 	s = " " + s;
 	int cntd = 0, cntr = 0;

 	for(int i = 1; true; ++i){
 		if(s[i] == 'D'){
 			if(cntr > 0){
 				--cntr;
 			}
 			else{
 				++cntd;
 				s += "D";
 			}
 		}
 		else{
 			if(cntd > 0){
 				--cntd;			
 			}
 			else{
 				++cntr;
 				s += "R";
 			}
 		}

 		if(cntd >= n || cntr >= n){
 			cout << s[s.size() - 1];
 			return 0;
 		}
 	}
}