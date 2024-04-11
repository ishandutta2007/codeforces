#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int SQN = 256;
const int SZ = (N / SQN) + 5;
int n;
int arr[N];
int lastans;
int q;
int type , ql , qr , k;
int start[SZ];
int finish[SZ];
int que[SZ][SQN + 1];
int f[SZ];
int r[SZ];
unsigned char freq[SZ][N];
int block[N];
int cur;
inline void push(int block , int val){
	que[block][r[block]] = val;
	r[block] = (r[block] + 1) & 255;
}
inline int front(int block){
	return que[block][f[block]];
}
inline void pop(int block){
	f[block] = (f[block] + 1) & 255;
}
void decomp(){
	cur = 0;
	for(int i = 1 ; i <= n ; i += SQN - 1){
		int j = min(n , i + SQN - 2);
		++cur;
		start[cur] = i;
		finish[cur] = j;
		for(int k = j ; k >= i ; --k){
			block[k] = cur;
			push(cur , arr[k]);
			++freq[cur][arr[k]];
		}
	}
}
void query(int ql , int qr , int k){
	lastans = 0;
	for(int i = block[ql] ; i <= block[qr] ; ++i){
		if(start[i] >= ql && finish[i] <= qr){
			lastans += int(freq[i][k]);
		}
		else if(freq[i][k]){
			int idx = finish[i];
			for(int j = f[i] ; j != r[i] ; j = (j + 1) & 255){
				if(idx >= ql && idx <= qr && que[i][j] == k){
					++lastans;
				}
				--idx;
			}
		}
	}
}
void update(int ql , int qr){
	int bl = block[ql];
	int br = block[qr];
	if(bl == br){
		int idx = finish[br];
		for(int i = f[br] ; i != r[br] ; i = (i + 1) & 255){
			if(idx <= qr && (idx - 1) >= ql){
				swap(que[br][i] , que[br][(i + 1) & 255]);
			}
			--idx;
		}
		return;
	}
	int rektval = -1;
	for(int i = finish[br] ; i >= start[br] ; --i){
		int val = front(br);
		pop(br);
		if(i == qr){
			rektval = val;
		}
		else{
			push(br , val);
		}
	}
	--freq[br][rektval];
	++freq[bl][rektval];
	for(int i = finish[bl] ; i >= start[bl] ; --i){
		int val = front(bl);
		pop(bl);
		push(bl , val);
		if(i == ql){
			push(bl , rektval);
		}
	}
	for(int i = bl ; i < br ; ++i){
		int val = front(i);
		pop(i);
		--freq[i][val];
		++freq[i + 1][val];
		push(i + 1 , val);
	}
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	decomp();
	scanf("%d" , &q);
	while(q--){
		scanf("%d %d %d" , &type , &ql , &qr);
		ql = ((ql + lastans - 1) % n) + 1;
		qr = ((qr + lastans - 1) % n) + 1;
		if(ql > qr){
			swap(ql , qr);
		}
		if(type == 1){
			update(ql , qr);
		}
		else{
			scanf("%d" , &k);
			k = ((k + lastans - 1) % n) + 1;
			query(ql , qr , k);
			printf("%d\n" , lastans);
		}
	}
}