#include "bits/stdc++.h"
using namespace std;
const int N = 205;
int n;
long long l;
int arr[N];
string str[N];
map < string , int > mp;
map < int , long long > score;
int cur;
long long ans;
struct matrix{
	long long arr[N][N];
	void reset(){
		for(int i = 1 ; i <= cur ; ++i){
			for(int j = 1 ; j <= cur ; ++j){
				arr[i][j] = -1e17;
			}
		}
	}
	void makeiden(){
		reset();
		for(int i = 1 ; i <= cur ; ++i){
			arr[i][i] = 0;
		}
	}
	matrix operator * (const matrix &o) const {
		matrix res;
		for(int i = 1 ; i <= cur ; ++i){
			for(int j = 1 ; j <= cur ; ++j){
				res.arr[i][j] = -1e17;
				for(int k = 1 ; k <= cur ; ++k){
					res.arr[i][j] = max(res.arr[i][j] , arr[i][k] + o.arr[k][j]);
				}
			}
		}
		return res;
	}
};
matrix power(matrix a , long long b){
	matrix res;
	res.makeiden();
	while(b){
		if(b & 1){
			res = res * a;
		}
		a = a * a;
		b >>= 1;
	}
	return res;
}
matrix base;
bool suffix(const string &big , const string &small){
	if(small.size() > big.size()){
		return 0;
	}
	int x = int(big.size()) - 1;
	int y = int(small.size()) - 1;
	while(y >= 0){
		if(big[x] != small[y]){
			return 0;
		}
		--x;
		--y;
	}
	return 1;
}
int main(){
	cur = 0;
	score.clear();
	mp.clear();
	cin >> n >> l;
	for(int i = 1 ; i <= n ; ++i){
		cin >> arr[i];
	}
	mp[""] = ++cur;
	for(int i = 1 ; i <= n ; ++i){
		cin >> str[i];
		string tmp = "";
		for(auto it : str[i]){
			tmp += it;
			if(mp.find(tmp) == mp.end()){
				mp[tmp] = ++cur;
			}
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		for(auto it : mp){
			if(suffix(it.first , str[i])){
				score[it.second] += arr[i];
			}
		}
	}
	base.makeiden();
	for(auto it1 : mp){
		for(auto it2 : mp){
			if(it2.first.size()){
				if(suffix(it1.first , it2.first.substr(0 , it2.first.size() - 1))){
					base.arr[it1.second][it2.second] = max(base.arr[it1.second][it2.second] , score[it2.second]);
				}
			}
		}
	}
	base = power(base , l);
	ans = 0;
	for(int i = 1 ; i <= cur ; ++i){
		ans = max(ans , base.arr[1][i]);
	}
	printf("%lld\n" , ans);
}