#include "bits/stdc++.h"
using namespace std;
const int N = 505;
int n;
char str[N][N];
vector < pair < int , int > > v;
int cross(pair < int , int > a , pair < int , int > b){
	return a.first * b.second - a.second * b.first;
}
pair < int , int > operator - (pair < int , int > a , pair < int , int > b){
	return make_pair(a.first - b.first , a.second - b.second);
}
bool useless(pair < int , int > lft , pair < int , int > mid , pair < int , int > rgt){
	return (cross(mid - lft , rgt - lft) >= 0);
}
bool cmp(pair < int , int > a , pair < int , int > b){
	int c = cross(a - v[0] , b - v[0]);
	if(c < 0){
		return 1;
	}
	if(c > 0){
		return 0;
	}
	return a < b;
}
int main(){
	while(~scanf("%d" , &n)){
		if(n == 0){
			break;
		}
		for(int i = 1 ; i <= n ; ++i){
			scanf("%s" , str[i] + 1);
		}
		v.clear();
		for(int i = 1 ; i < n ; ++i){
			for(int j = 1 ; j < n ; ++j){
				if(str[i][j] > '0' && str[i][j + 1] > '0' && str[i + 1][j] > '0' && str[i + 1][j + 1] > '0'){
					v.emplace_back(j , n - i);
				}
			}
		}
		sort(v.begin() , v.end());
		sort(v.begin() + 1 , v.end() , cmp);
		vector < pair < int , int > > hull;
		for(auto it : v){
			while(hull.size() >= 2 && useless(hull[hull.size() - 2] , hull[hull.size() - 1] , it)){
				hull.pop_back();
			}
			hull.emplace_back(it);
		}
		printf("%d\n" , int(hull.size()));
		for(auto it : hull){
			printf("%d %d\n" , it.first , it.second);
		}
	}
}