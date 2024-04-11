#include <iostream>
 
using namespace std;
 
bool is_O[1000000];
int prec[1000001];
 
int main(){
	string s;
	cin >> s;
	int len = s.size();
	fill(is_O, is_O + 1000000, 0);
	prec[0] = 0;
	prec[1] = 0;
	for(int i=1;i<len;i++){
		if(s[i] == 'o'){
			is_O[i] = 1;
			prec[i + 1] = prec[i];
		}else if(s[i] == 'v' && s[i-1] == 'v'){
			prec[i + 1] = prec[i] + 1;
		}else{
			prec[i + 1] = prec[i];
		}
	}
	long long ans = 0;
	for(int i=0;i<len;i++){
		if(is_O[i]){
			ans += (long long)prec[i] * (prec[len] - prec[i]);
		}
	}
	cout << ans;
}