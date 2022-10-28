#include "bits/stdc++.h"
using namespace std;
const int N = 2e6 + 6;
int n;
char str[N];
char ans[N];
string arr[N];
int len;
int idx;
vector < int > v[N];
int m;
vector < pair < int , pair < int , int > > > tmp;
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%s" , str);
		arr[i] = str;
		scanf("%d" , &len);
		while(len--){
			scanf("%d" , &idx);
			v[idx].push_back(i);
			m = max(m , idx + int(arr[i].size()) - 1);
		}
	}
	for(int i = 1 ; i <= m ; ++i){
		for(int x : v[i]){
			tmp.emplace_back(make_pair(i + arr[x].size() - 1 , make_pair(x , i)));
		}
		while(!tmp.empty() && tmp.back().first < i){
			tmp.pop_back();
		}
		if(tmp.empty()){
			printf("a");
		}
		else{
			printf("%c" , arr[tmp.back().second.first][i - tmp.back().second.second]);
		}
	}
	printf("\n");
}