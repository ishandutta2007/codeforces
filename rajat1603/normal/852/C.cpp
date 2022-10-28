#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int b[N];
vector < pair < int , pair < int , int > > > v;
set < int > s;
int ans[N];
int main(){
	scanf("%d" , &n);
	for(int i = 0 ; i < n ; ++i){
		scanf("%d" , b + 2 * i);
	}
	v.clear();
	s.clear();
	for(int i = 0 ; i < n ; ++i){
		s.insert(i);
	}
	for(int ii = 0 ; ii < n ; ++ii){
		int idx = ii * 2 + 1;
		int prv = (idx + 2 * n - 1) % (2 * n);
		int nxt = (idx + 1) % (2 * n);
		int lft , rgt;
		lft = n - b[prv];
		rgt = b[nxt];
		v.emplace_back(make_pair(abs(rgt - lft) , make_pair(rgt - lft , ii)));
	}
	sort(v.begin() , v.end());
	reverse(v.begin() , v.end());
	for(auto it : v){
		if(it.second.first < 0){
			ans[it.second.second] = *s.begin();
			s.erase(s.begin());
		}
		else{
			ans[it.second.second] = *prev(s.end());
			s.erase(prev(s.end()));
		}
	}
	for(int i = 0 ; i < n ; ++i){
		printf("%d%c" , ans[i] , " \n"[i == n - 1]);
	}
}