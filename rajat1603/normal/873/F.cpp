#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const int LN = 18;
int sa[LN + 1][N];
int finalsa[N];
int lcp[N];
pair < pair < int , int > , int > tmp[N];
int n;
char str[N];
void build(){
	for(int i = 1 ; i <= n ; ++i){
		sa[0][i] = str[i] - 'a' + 1;
	}
	tmp[0] = make_pair(make_pair(-2 , -2) , -2);
	for(int lg = 1 ; lg <= LN ; ++lg){
		for(int i = 1 ; i <= n ; ++i){
			int x = i + (1 << (lg - 1));
			tmp[i] = make_pair(make_pair(sa[lg - 1][i] , (x <= n) ? sa[lg - 1][x] : -1) , i);
		}
		sort(tmp + 1 , tmp + 1 + n);
		int cur = 0;
		for(int i = 1 ; i <= n ; ++i){
			cur += tmp[i - 1].first != tmp[i].first;
			sa[lg][tmp[i].second] = cur;
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		finalsa[sa[LN][i]] = i;
	}
	for(int i = 1 ; i < n ; ++i){
		lcp[i] = 0;
		int x = finalsa[i];
		int y = finalsa[i + 1];
		for(int j = LN ; j >= 0 ; --j){
			if(sa[j][x] == sa[j][y]){
				lcp[i] += 1 << j;
				x += 1 << j;
				y += 1 << j;
			}
		}
	}
	lcp[n] = 0;
}
char cst[N];
int sum[N];
long long ans;
int lft[N];
int rgt[N];
int main(){
	scanf("%d" , &n);
	scanf("%s" , str + 1);
	scanf("%s" , cst + 1);
	reverse(str + 1 , str + 1 + n);
	reverse(cst + 1 , cst + 1 + n);
	build();
	sum[0] = 0;
	for(int i = 1 ; i <= n ; ++i){
		int idx = finalsa[i];
		if(cst[idx] == '1'){
			sum[i] = sum[i - 1];
		}
		else{
			sum[i] = sum[i - 1] + 1;
		}
	}
	ans = 0;
	for(int i = 1 ; i <= n ; ++i){
		int idx = finalsa[i];
		if(cst[idx] == '0'){
			ans = max(ans , n - idx + 1LL);
		}
	}
	stack < int > s;
	while(!s.empty()){
		s.pop();
	}
	for(int i = 1 ; i < n ; ++i){
		while(!s.empty() && lcp[i] <= lcp[s.top()]){
			s.pop();
		}
		if(s.empty()){
			lft[i] = 1;
		}
		else{
			lft[i] = s.top() + 1;
		}
		s.push(i);
	}
	while(!s.empty()){
		s.pop();
	}
	for(int i = n - 1 ; i >= 1 ; --i){
		while(!s.empty() && lcp[i] <= lcp[s.top()]){
			s.pop();
		}
		if(s.empty()){
			rgt[i] = n;
		}
		else{
			rgt[i] = s.top();
		}
		s.push(i);
	}
	for(int i = 1 ; i < n ; ++i){
		int ql = lft[i];
		int qr = rgt[i];
		ans = max(ans , 1LL * lcp[i] * (sum[qr] - sum[ql - 1]));
	}
	printf("%lld\n" , ans);
}