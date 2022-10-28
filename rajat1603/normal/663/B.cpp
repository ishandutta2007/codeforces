#include "bits/stdc++.h"
using namespace std;
const int MAGIC = 1e5 + 5;
int t;
char tmp1 , tmp2 , tmp3 , tmp4;
map < string , long long > ans;
void pre(){
	ans.clear();
	ans["9"] = 1989;
	for(int i = 0 ; i < 9 ; ++i){
		ans[to_string(i)] = 1990 + i;
	}
	for(int i = 1999 ; i < MAGIC ; ++i){
		string tmp = to_string(i);
		string num = "";
		reverse(tmp.begin() , tmp.end());
		for(char x : tmp){
			num = x + num;
			if(ans.find(num) == ans.end()){
				ans[num] = i;
				break;
			}
		}	
	}
}
long long toll(string s){
	long long num = 0;
	for(char c : s){
		num *= 10;
		num += c - '0';
	}
	return num;
}
int main(){
	pre();
	cin >> t;
	while(t--){
		cin >> tmp1 >> tmp2 >> tmp3 >> tmp4;
		string str;
		cin >> str;
		if(ans.find(str) != ans.end()){
			printf("%lld\n" , ans[str]);
			continue;
		}
		string x = "";
		long long lst = 0;
		int dij = 0;
		long long pw = 1;
		reverse(str.begin() , str.end());
		for(char c : str){
			x = c + x;
			pw *= 10;
			++dij;
			if(ans.find(x) != ans.end()){
				lst = ans[x];
			}
			else{
				//find first number larger than lst with this suffix
				long long cur = toll(x);
				long long tmp = cur;
				while(cur <= lst || (cur % pw) != tmp){
					cur += pw / 10;
				}
				lst = cur;
			}
		}
		printf("%lld\n" , lst);
	}
}