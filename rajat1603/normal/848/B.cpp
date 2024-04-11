#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , w , h;
int type[N];
int x[N] , y[N] , t[N];
vector < pair < int , int > > v;
int where[N];
vector < pair < int , int > > dwn , lft;
void solve(int l , int r){
	dwn.clear();
	lft.clear();
	for(int ii = l ; ii <= r ; ++ii){
		int idx = v[ii].second;
		if(y[idx] <= 0){
			dwn.emplace_back(make_pair(x[idx] , idx));
		}
		if(x[idx] <= 0){
			lft.emplace_back(make_pair(y[idx] , idx));
		}
	}
	sort(dwn.begin() , dwn.end());
	sort(lft.begin() , lft.end());
	for(int i = 0 ; i < dwn.size() ; ++i){
		if(lft.size() + i >= dwn.size()){
			//cout << "D " << dwn[i].second << endl;
			where[dwn[i].second] = lft[dwn.size() - i - 1].second;
		}
		else{
			where[dwn[i].second] = dwn[lft.size() + i].second;
		}
	}
	for(int i = 0 ; i < lft.size() ; ++i){
		if(dwn.size() + i >= lft.size()){
			where[lft[i].second] = dwn[lft.size() - i - 1].second;
		}
		else{
			//cout << "L " << lft[i].second << endl;
			where[lft[i].second] = lft[dwn.size() + i].second;
		}
	}
}
int main(){
	scanf("%d %d %d" , &n , &w , &h);
	v.clear();
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , type + i);
		int a , b;
		scanf("%d %d" , &a , &b);
		if(type[i] == 1){//vertical
			x[i] = a;
			y[i] = -b;
		}
		else{
			x[i] = -b;
			y[i] = a;
		}
		v.emplace_back(make_pair(x[i] + y[i] , i));
	}
	sort(v.begin() , v.end());
	for(int i = 0 ; i < v.size() ; ++i){
		int j = i;
		while(j + 1 < v.size() && v[j + 1].first == v[j].first){
			++j;
		}
		solve(i , j);
		i = j;
	}
	for(int i = 1 ; i <= n ; ++i){
		if(y[where[i]] <= 0){
			printf("%d %d\n" , x[where[i]] , h);
		}
		else{
			printf("%d %d\n" , w , y[where[i]]);
		}
	}
}