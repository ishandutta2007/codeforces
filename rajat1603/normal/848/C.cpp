#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int SQN = 350;
int n , m;
int arr[N];
set < pair < int , int > > s;
int bit1[(N / SQN) + 5][N];
int bit2[(N / SQN) + 5][N];
int nxt[N];
int prv[N];
int lst[N];
int block[N];
int start[N];
int finish[N];
int cur;
void update1(int x , int y , int val){
	++y;
	while(y <= n){
		bit1[x][y] += val;
		y += y & -y;
	}
}
void update2(int x , int y , int val){
	--y;
	while(y){
		bit2[x][y] += val;
		y -= y & -y;
	}
}
int query1(int x , int y){
	++y;
	int res = 0;
	while(y){
		res += bit1[x][y];
		y -= y & -y;
	}
	return res;
}
int query2(int x , int y){
	--y;
	int res = 0;
	while(y <= n){
		res += bit2[x][y];
		y += y & -y;
	}
	return res;
}
void update(int idx , int val){
	int old = arr[idx];
	if(old == val){
		return;
	}
	if(prv[idx] != 0){
		update2(block[prv[idx]] , nxt[prv[idx]] , -prv[idx]);
		update2(block[prv[idx]] , nxt[idx] , prv[idx]);
		nxt[prv[idx]] = nxt[idx];
	}
	if(nxt[idx] != n + 1){
		update1(block[nxt[idx]] , prv[nxt[idx]] , -nxt[idx]);
		update1(block[nxt[idx]] , prv[idx] , nxt[idx]);
		prv[nxt[idx]] = prv[idx];
	}
	update1(block[idx] , prv[idx] , -idx);
	update2(block[idx] , nxt[idx] , -idx);
	s.erase(make_pair(old , idx));
	arr[idx] = val;
	auto it = s.lower_bound(make_pair(val , idx));
	if(it == s.end() || it -> first != val){
		nxt[idx] = n + 1;
		update2(block[idx] , nxt[idx] , idx);
	}
	else{
		nxt[idx] = it -> second;
		update2(block[idx] , nxt[idx] , idx);
		update1(block[it -> second] , prv[it -> second] , -it -> second);
		prv[it -> second] = idx;
		update1(block[it -> second] , prv[it -> second] , it -> second);
	}
	if(it == s.begin()){
		prv[idx] = 0;
		update1(block[idx] , prv[idx] , idx);
	}
	else{
		--it;
		if(it -> first == val){
			prv[idx] = it -> second;
			update1(block[idx] , prv[idx] , idx);
			update2(block[it -> second] , nxt[it -> second] , -it -> second);
			nxt[it -> second] = idx;
			update2(block[it -> second] , nxt[it -> second] , it -> second);
		}
		else{
			prv[idx] = 0;
			update1(block[idx] , prv[idx] , idx);
		}
	}
	s.insert(make_pair(val , idx));
}
void query(int ql , int qr){
	long long res = 0;
	for(int i = block[ql] ; i <= block[qr] ; ++i){
		if(start[i] >= ql && finish[i] <= qr){
			res += query2(i , qr + 1);
			res -= query1(i , ql - 1);
		}
		else{
			for(int j = max(ql , start[i]) ; j <= min(qr , finish[i]) ; ++j){
				if(nxt[j] > qr){
					res += j;
				}
				if(prv[j] < ql){
					res -= j;
				}
			}
		}
	}
	printf("%lld\n" , res);
}
int main(){
	scanf("%d %d" , &n , &m);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	s.clear();
	for(int i = 1 ; i <= n ; ++i){
		s.insert(make_pair(arr[i] , i));
	}
	for(int i = 1 ; i <= n ; ++i){
		lst[i] = 0;
	}
	for(int i = 1 ; i <= n ; ++i){
		prv[i] = lst[arr[i]];
		lst[arr[i]] = i;
	}
	for(int i = 1 ; i <= n ; ++i){
		lst[i] = n + 1;
	}
	for(int i = n ; i >= 1 ; --i){
		nxt[i] = lst[arr[i]];
		lst[arr[i]] = i;
	}
	cur = 0;
	for(int i = 1 ; i <= n ; i += SQN){
		int l = i;
		int r = min(n , i + SQN - 1);
		++cur;
		start[cur] = l;
		finish[cur] = r;
		for(int j = l ; j <= r ; ++j){
			block[j] = cur;
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		update1(block[i] , prv[i] , i);
	}
	for(int i = 1 ; i <= n ; ++i){
		update2(block[i] , nxt[i] , i);
	}
	while(m--){
		int type;
		scanf("%d" , &type);
		if(type == 1){
			int idx , val;
			scanf("%d %d" , &idx , &val);
			update(idx , val);
		}
		else{
			int l , r;
			scanf("%d %d" , &l , &r);
			query(l , r);
		}
	}
}