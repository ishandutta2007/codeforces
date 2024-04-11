#include "bits/stdc++.h"
using namespace std;
const int N = 1e4 + 4;
char str[N];
int n;
set < string > s;
int dp[4][N];
bool possible(int len , int pos){
	if(pos > n){
		return 1;
	}
	if(dp[len][pos] != -1){
		return dp[len][pos];
	}
	bool ret = 0;
	if(pos + 1 <= n){
		string tmp1 = "";
		tmp1 += str[pos];
		tmp1 += str[pos + 1];
		string tmp2 = "";
		for(int i = pos - len ; i < pos ; ++i){
			tmp2 += str[i];
		}
		if(tmp1 != tmp2){
			ret |= possible(2 , pos + 2);
		}
	}
	if(pos + 2 <= n){
		string tmp1 = "";
		tmp1 += str[pos];
		tmp1 += str[pos + 1];
		tmp1 += str[pos + 2];
		string tmp2 = "";
		for(int i = pos - len ; i < pos ; ++i){
			tmp2 += str[i];
		}
		if(tmp1 != tmp2){
			ret |= possible(3 , pos + 3);
		}
	}
	return dp[len][pos] = ret;
}
int main(){
	memset(dp , -1 , sizeof(dp));
	scanf("%s" , str + 1);
	n = strlen(str + 1);
	for(int i = 6 ; i <= n ; ++i){
		if(i + 1 <= n){
			if(possible(2 , i + 2)){
				string tmp = "";
				tmp += str[i];
				tmp += str[i + 1];
				s.insert(tmp);
			}
		}
		if(i + 2 <= n){
			if(possible(3 , i + 3)){
				string tmp = "";
				tmp += str[i];
				tmp += str[i + 1];
				tmp += str[i + 2];
				s.insert(tmp);
			}
		}
	}
	printf("%d\n" , int(s.size()));
	for(auto it : s){
		cout << it << "\n";
	}
}