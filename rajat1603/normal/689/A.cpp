#include "bits/stdc++.h"
using namespace std;
string str[5] = {"#####" , "#123#" , "#456#" , "#789#" , "##0##"};
const int N = 100;
int n;
char arr[N];
vector < pair < int , int > > d;
pair < int , int > get(char s , char t){
	int dx;
	int dy;
	for(int i = 0 ; i < 5 ; ++i){
		for(int j = 0 ; j < 5 ; ++j){
			if(str[i][j] == t){
				dx = i;
				dy = j;
			}
		}
	}
	for(int i = 0 ; i < 5 ; ++i){
		for(int j = 0 ; j < 5 ; ++j){
			if(str[i][j] == s){
				dx -= i;
				dy -= j;
			}
		}
	}
	return {dx , dy};
}
bool ok(int x , int y){
	if(str[x][y] == '#'){
		return 0;
	}
	for(auto it : d){
		x += it.first;
		y += it.second;
		if(x >= 5 || y >= 5 || x < 0 || y < 0 || str[x][y] == '#'){
			return 0;
		}
	}
	return 1;
}
int main(){
	scanf("%d" , &n);
	scanf("%s" , arr + 1);
	d.clear();
	for(int i = 2 ; i <= n ; ++i){
		d.emplace_back(get(arr[i - 1] , arr[i]));
	}
	int cnt = 0;
	for(int i = 0 ; i < 5 ; ++i){
		for(int j = 0 ; j < 5 ; ++j){
			if(ok(i , j)){
				++cnt;
			}
		}
	}
	if(cnt > 1){
		printf("NO\n");
	}
	else{
		printf("YES\n");
	}
}