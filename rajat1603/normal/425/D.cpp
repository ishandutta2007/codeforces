#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int SQN = 330;
int n;
int x , y;
vector < int > v[N];
long long ans;
vector < int > large;
bool check(int x , int y){
	auto it = lower_bound(v[x].begin() , v[x].end() , y);
	return (it != v[x].end() && (*it == y));
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d %d" , &x , &y);
		v[x].emplace_back(y);
	}
	for(int x = 0 ; x < N ; ++x){
		sort(v[x].begin() , v[x].end());
	}
	for(int x = 0 ; x < N ; ++x){
		if(v[x].size() <= SQN){
			for(int i = 0 ; i < v[x].size() ; ++i){
				for(int j = i + 1 ; j < v[x].size() ; ++j){
					int dif = v[x][j] - v[x][i];
					int x1 = x - dif;
					int y1 = v[x][i];
					int y2 = v[x][j];
					if(x1 >= 0){
						ans += (check(x1 , y1) && check(x1 , y2));
					}
					x1 = x + dif;
					if(x1 < N && (v[x1].size() > SQN)){
						ans += (check(x1 , y1) && check(x1 , y2));
					}
				}
			}
		}
		else{
			large.emplace_back(x);
		}
	}
	for(int i = 0 ; i < large.size() ; ++i){
		for(int j = i + 1 ; j < large.size() ; ++j){
			int x1 = large[i];
			int x2 = large[j];
			for(int y1 : v[x1]){
				int y2 = y1 + x2 - x1;
				ans += (check(x2 , y1) && check(x1 , y2) && check(x2 , y2));
			}
		}
	}
	printf("%lld\n" , ans);
}