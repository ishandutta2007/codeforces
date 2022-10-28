#include "bits/stdc++.h"
using namespace std;
const int N = 505;
int n , m;
int arr[N];
int basis[N][N];
char str[N];
int q;
vector < string > v;
int inv[] = {0 , 1 , 3 , 2 , 4};
int siz;
int insert(string &str){
	for(int i = 0 ; i < m ; ++i){
		arr[i] = str[i] - 'a';
	}
	for(int i = 0 ; i < m ; ++i){
		if(arr[i]){
			if(basis[i][i]){
				int c = (arr[i] * inv[basis[i][i]]) % 5;
				for(int j = i ; j < m ; ++j){
					arr[j] = (((arr[j] - basis[i][j] * c) % 5) + 5) % 5;
				}
			}
			else{
				for(int j = 0 ; j < m ; ++j){
					basis[i][j] = arr[j];
				}
				return i;
			}
		}
	}
	return -1;
}
const int mod = 1e9 + 7;
int power[N];
int main(){
	scanf("%d %d" , &n , &m);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%s" , str);
		v.emplace_back(str);
	}
	sort(v.begin() , v.end());
	reverse(v.begin() , v.end());
	siz = n;
	for(auto &it : v){
		siz -= insert(it) != -1;
	}
	scanf("%d" , &q);
	v.clear();
	power[0] = 1;
	for(int i = 1 ; i < N ; ++i){
		power[i] = (5LL * power[i - 1]) % mod;
	}
	while(q--){
		scanf("%s" , str);
		v.emplace_back(str);
		int tmp = insert(v.back());
		v.clear();
		if(tmp == -1){
			printf("%d\n" , power[siz]);
		}
		else{
			printf("0\n");
			for(int j = 0 ; j < m ; ++j){
				basis[tmp][j] = 0;
			}
		}
	}
}