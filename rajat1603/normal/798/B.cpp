#include "bits/stdc++.h"
using namespace std;
const int N = 55;
const int inf = 1e5 + 5;
int n;
string str[N];
int ans;
void rotate(string &s){
	for(int i = 1 ; i < s.size() ; ++i){
		swap(s[i] , s[i - 1]);
	}
}
int main(){
	cin >> n;
	ans = inf;
	for(int i = 1 ; i <= n ; ++i){
		cin >> str[i];
	}
	for(int i = 0 ; i < str[1].size() ; ++i){
		int cur = i;
		for(int j = 2 ; j <= n ; ++j){
			int when = inf;
			for(int k = 0 ; k < str[j].size() ; ++k){
				if(str[j] == str[1]){
					when = min(when , k);
				}
				rotate(str[j]);
			}
			cur += when;
		}
		ans = min(ans , cur);
		rotate(str[1]);
	}
	if(ans >= inf){
		ans = -1;
	}
	printf("%d\n" , ans);
}