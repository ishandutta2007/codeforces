#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , m;
vector < pair < int , string > > v[N];
string str;
int group , score;
int main(){
	cin >> n >> m;
	for(int i = 1 ; i <= n ; ++i){
		cin >> str >> group >> score;
		v[group].emplace_back(make_pair(score , str));
	}
	for(int i = 1 ; i <= m ; ++i){
		sort(v[i].begin() , v[i].end());
		reverse(v[i].begin() , v[i].end());
		if(v[i].size() > 2 && v[i][2].first == v[i][1].first){
			cout << "?\n";
		}
		else{
			cout << v[i][0].second << " " << v[i][1].second << "\n";
		}
	}
}