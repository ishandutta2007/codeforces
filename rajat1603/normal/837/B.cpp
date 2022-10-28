#include "bits/stdc++.h"
using namespace std;
const int N = 105;
int n , m;
char str[N][N];
bool check(int x1 , int y1 , int x2 , int y2 , char c){
	for(int i = x1 ; i <= x2 ; ++i){
		for(int j = y1 ; j <= y2 ; ++j){
			if(str[i][j] != c){
				return 0;
			}
		}
	}
	return 1;
}
int main(){
	scanf("%d %d" , &n , &m);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%s" , str[i] + 1);
	}
	if(n % 3 == 0){
		int x = n / 3;
		vector < char > v;
		v.clear();
		v.emplace_back('R');
		v.emplace_back('G');
		v.emplace_back('B');
		sort(v.begin() , v.end());
		do{
			bool ok = check(1 , 1 , x , m , v[0]) && check(x + 1 , 1 , x + x , m , v[1]) && check(x + x + 1 , 1 , x + x + x , m , v[2]);
			if(ok){
				printf("YES\n");
				return 0;
			}
		}
		while(next_permutation(v.begin() , v.end()));
	}
	if(m % 3 == 0){
		int x = m / 3;
		vector < char > v;
		v.clear();
		v.emplace_back('R');
		v.emplace_back('G');
		v.emplace_back('B');
		sort(v.begin() , v.end());
		do{
			bool ok = check(1 , 1 , n , x , v[0]) && check(1 , x + 1 , n , x + x , v[1]) && check(1 , x + x + 1 , n , x + x + 1 , v[2]);
			if(ok){
				printf("YES\n");
				return 0;
			}
		}
		while(next_permutation(v.begin() , v.end()));	
	}
	printf("NO\n");
}