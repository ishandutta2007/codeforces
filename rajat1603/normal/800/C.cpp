#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n , m;
int arr[N];
int all[N];
pair < int , int > tmp[N];
int siz;
vector < int > v[N];
vector < int > c[N];
int dp[N];
int pr[N];
int wo[N];
int mx[N];
void setmax(int idx , int val , int i){
	if(val > mx[idx]){
		mx[idx] = val;
		wo[idx] = i;
	}
}
vector < int > ss;
vector < int > ans;
int phi(int x){
	int res = 0;
	for(int i = 1 ; i <= x ; ++i){
		if(__gcd(i , x) == 1){
			++res;
		}
	}
	return res;
}
int power(int a , int b){
	int res = 1;
	while(b){
		if(b & 1){
			res = (1LL * res * a) % m;
		}
		a = (1LL * a * a) % m;
		b >>= 1;
	}
	return res;
}
int main(){
	scanf("%d %d" , &n , &m);
	for(int i = 0 ; i < m ; ++i){
		all[i] = 1;
	}
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
		all[arr[i]] = 0; 
	}
	siz = 0;
	for(int i = 1 ; i < m ; ++i){
		if(all[i]){
			tmp[++siz] = {__gcd(i , m) , i};
		}
	}
	sort(tmp + 1 , tmp + 1 + siz);
	for(int i = 1 ; i <= m ; ++i){
		for(int j = i ; j <= m ; j += i){
			v[j].emplace_back(i);
		}
	}
	for(int i = 1 ; i <= siz ; ++i){
		c[tmp[i].first].emplace_back(tmp[i].second);
	}
	for(int i = 1 ; i <= siz ; ++i){
		dp[i] = 1;
		for(int j : v[tmp[i].first]){
			int tmp = mx[j] + 1;
			if(tmp > dp[i]){
				dp[i] = tmp;
				pr[i] = wo[j];
			}
		}
		setmax(tmp[i].first , dp[i] , i);
	}
	ss.clear();
	int idx = -1;
	int val = 0;
	for(int i = 1 ; i <= siz ; ++i){
		if(idx == -1){
			idx = i;
			val = dp[i];
		}
		else if(dp[i] > val){
			val = dp[i];
			idx = i;
		}
	}
	ss.clear();
	if(idx != -1){
		while(idx){
			ss.emplace_back(idx);
			idx = pr[idx];
		}
	}
	reverse(ss.begin() , ss.end());
	ans.clear();
	if(!ss.empty()){
		ans.emplace_back(tmp[ss[0]].second);
	}
	int ph = phi(m);
	for(int i = 1 ; i < ss.size() ; ++i){
		int x = tmp[ss[i - 1]].second;
		int y = tmp[ss[i]].second;
		int d = __gcd(x , y);
		int M = x / d;
		int N = y / d;
		int a = (1LL * N * power(M , ph - 1)) % m;
		ans.emplace_back(a);
	}
	if(all[0]){
		ans.emplace_back(0);
	}
	printf("%d\n" , int(ans.size()));
	for(int i = 1 ; i <= ans.size() ; ++i){
		printf("%d%c" , ans[i - 1] , " \n"[i == ans.size()]);
	}
}