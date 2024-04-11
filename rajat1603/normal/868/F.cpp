#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const int K = 25;
int n , k;
int arr[N];
long long dp[2][N];
int cnt[N];
struct data{
	int l;
	int r;
	int ql;
	int qr;
	data(int a , int b , int c , int d){
		l = a;
		r = b;
		ql = c;
		qr = d;
	}
	data(){

	}
};
data curarr[N];
int siz1;
data nxt[N];
int siz2;
long long value;
void insert(int idx){
	value += cnt[arr[idx]];
	++cnt[arr[idx]];
}
void remove(int idx){
	--cnt[arr[idx]];
	value -= cnt[arr[idx]];
}
void solve(int layer){
	siz1 = 0;
	curarr[++siz1] = data(1 , n , 1 , n);
	while(siz1){
		siz2 = 0;
		int curr = n;
		int curl = n + 1;
		memset(cnt , 0 , sizeof(cnt));
		value = 0;
		while(siz1){
			int l = curarr[siz1].l;
			int r = curarr[siz1].r;
			int ql = curarr[siz1].ql;
			int qr = curarr[siz1].qr;
			--siz1;
			if(l > r){
				continue;
			}
			int mid = l + r >> 1;
			int ll = max(mid , ql);
			int rr = qr;
			while(curl > mid){
				insert(curl - 1);
				--curl;	
			}
			while(curr > rr){
				remove(curr);
				--curr;
			}
			long long res = 1LL << 50;
			int idx = -1;
			while(curr > ll){
				long long tmp = value + dp[!layer][curr + 1];
				if(tmp < res){
					res = tmp;
					idx = curr;
				}
				remove(curr);
				--curr;
			}
			if(curr == ll && value + dp[!layer][curr + 1] < res){
				res = value + dp[!layer][curr + 1];
				idx = curr;
			}
			dp[layer & 1][mid] = res;
			nxt[++siz2] = data(mid + 1 , r , idx , qr);
			nxt[++siz2] = data(l , mid - 1 , ql , idx);
		}
		for(int i = 1 ; i <= siz2 ; ++i){
			curarr[siz2 - i + 1] = nxt[i];
		}
		siz1 = siz2;
	}
}

int main(){
	scanf("%d %d" , &n , &k);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	for(int i = n ; i >= 1 ; --i){
		dp[1][i] = dp[1][i + 1] + cnt[arr[i]];
		++cnt[arr[i]];
	}
	for(int i = 2 ; i <= k ; ++i){
		solve(i & 1);
	}
	printf("%lld\n" , dp[k & 1][1]);
}