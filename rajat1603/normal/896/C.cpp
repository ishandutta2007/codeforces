#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , m , seed , vmax;
set < pair < pair < int , int > , long long > > s;
int rnd(){
    int ret = seed;
    seed = (seed * 7LL + 13LL) % 1000000007;
    return ret;
}
int power(int a , int b , int mod){
	int res = 1;
	while(b){
		if(b & 1){
			res = (1LL * res * a) % mod;
		}
		a = (1LL * a * a) % mod;
		b >>= 1;
	}
	return res;
}
void sum(int l , int r , int x , int mod){
	int res = 0;
	for(auto it : s){
		int ql = max(it.first.first , l);
		int qr = min(it.first.second , r);
		if(ql <= qr){
			res = (res + 1LL * power(it.second % mod , x , mod) * (qr - ql + 1LL)) % mod;
		}
	}
	printf("%d\n" , res);
}
pair < long long , int > arr[N];
int len;
void kth(int l , int r , int k){
	len = 0;
	for(auto it : s){
		int ql = max(it.first.first , l);
		int qr = min(it.first.second , r);
		if(ql <= qr){
			arr[++len] = make_pair(it.second , qr - ql + 1);
		}
	}
	sort(arr + 1 , arr + 1 + len);
	for(int i = 1 ; i <= len ; ++i){
		if(arr[i].second >= k){
			printf("%lld\n" , arr[i].first);
			return;
		}
		k -= arr[i].second;
	}
}
pair < pair < int , int > , long long > tmp[N];
void add(int ql , int qr , int x){
	len = 0;
	while(1){
		auto it = s.lower_bound(make_pair(make_pair(ql , -1) , -1));
		if(it -> first.first > qr){
			--it;
			if(it -> first.second < ql){
				break;
			}
		}
		int lft = it -> first.first;
		int rgt = it -> first.second;
		long long val = it -> second;
		s.erase(it);
		if(rgt > qr){
			s.insert(make_pair(make_pair(qr + 1 , rgt) , val));
		}
		if(lft < ql){
			s.insert(make_pair(make_pair(lft , ql - 1) , val));
		}
		tmp[++len] = make_pair(make_pair(max(lft , ql) , min(rgt , qr)) , val + x);
	}
	for(int i = 1 ; i <= len ; ++i){
		s.insert(tmp[i]);
	}
}
void fix(int ql , int qr , int x){
	while(1){
		auto it = s.lower_bound(make_pair(make_pair(ql , -1) , -1));
		if(it -> first.first > qr){
			--it;
			if(it -> first.second < ql){
				break;
			}
		}
		int lft = it -> first.first;
		int rgt = it -> first.second;
		long long val = it -> second;
		s.erase(it);
		if(rgt > qr){
			s.insert(make_pair(make_pair(qr + 1 , rgt) , val));
		}
		if(lft < ql){
			s.insert(make_pair(make_pair(lft , ql - 1) , val));
		}
	}
	s.insert(make_pair(make_pair(ql , qr) , x));
}
int main(){
	scanf("%d %d %d %d" , &n , &m , &seed , &vmax);
	s.insert(make_pair(make_pair(0 , 0) , 0));
	for(int i = 1 ; i <= n ; ++i){
		s.insert(make_pair(make_pair(i , i) , (rnd() % vmax) + 1));
	}
	s.insert(make_pair(make_pair(n + 1 , n + 1) , 0));
	while(m--){
		int op , l , r , x , y;
		op = (rnd() % 4) + 1;
		l = (rnd() % n) + 1;
		r = (rnd() % n) + 1;
		if(l > r){
			swap(l , r);
		}
		if(op == 3){
			x = (rnd() % (r - l + 1)) + 1;
		}
		else{
			x = (rnd() % vmax) + 1;
		}
		if(op == 4){
			y = (rnd() % vmax) + 1;
		}
		if(op == 1){
			add(l , r , x);
		}
		if(op == 2){
			fix(l , r , x);
		}
		if(op == 3){
			kth(l , r , x);
		}
		if(op == 4){
			sum(l , r , x , y);
		}
	}
}