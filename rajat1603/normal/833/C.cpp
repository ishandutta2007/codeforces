#include "bits/stdc++.h"
using namespace std;
string l , r;
long long a , b;
int ans;
int cnt[10];
int rrr[10];
int tot;
long long pw10[20];
long long rep[10][20];
void check(){
	memcpy(rrr , cnt , sizeof(rrr));
	rrr[0] += tot;
	long long cur = 0;
	long long tmp;
	int idx;
	for(int i = 0 ; i < r.size() ; ++i){
		tmp = cur;
		idx = -1;
		for(int j = r[i] - '0' - 1 ; j >= 0 ; --j){
			if(rrr[j]){
				idx = j;
				break;
			}
		}
		if(idx != -1){
			tmp = tmp * 10 + idx;
			--rrr[idx];
			for(int j = 9 ; j >= 0 ; --j){
				tmp = tmp * pw10[rrr[j]] + rep[j][rrr[j]];
			}
			++rrr[idx];
			if(tmp >= a){
				++ans;
				return;
			}
		}
		if(!rrr[r[i] - '0']){
			return;
		}
		--rrr[r[i] - '0'];
		cur = cur * 10 + r[i] - '0';
	}
	++ans;
}
void go(int dig , int lft){
	if(!lft){
		check();
		return;
	}
	if(dig > 9){
		return;
	}
	go(dig + 1 , lft);
	++cnt[dig];
	go(dig , lft - 1);
	--cnt[dig];
}
int main(){
	cin >> a >> b;
	l = to_string(a);
	r = to_string(b);
	pw10[0] = 1;
	for(int i = 1 ; i < 20 ; ++i){
		pw10[i] = pw10[i - 1] * 10;
	}
	for(int i = 1 ; i < 10 ; ++i){
		rep[i][0] = 0;
		for(int j = 1 ; j < 20 ; ++j){
			rep[i][j] = rep[i][j - 1] * 10 + i;
		}
	}
	for(int i = 1 ; i <= r.size() ; ++i){
		tot = r.size() - i;
		go(1 , i);
	}
	cout << ans << endl;
}