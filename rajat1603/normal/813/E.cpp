#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , k;
int arr[N];
int q;
int a , b;
int lastans;
 
const int SZ = 5e6 + 6;
struct data{
    int cnt;
    int left;
    int right;
    data(){
    	cnt = 0;
    	left = 0;
    	right = 0;
    }
};
data st[SZ];
int root[N];
int cur;
inline int newnode(int val3 , int left , int right){
	++cur;
	st[cur].cnt = val3;
	st[cur].left = left;
	st[cur].right = right;
	return cur;
}
void insert(int &curnode , int prenode , int l , int r , int idx , int val){
	if(l == r){
		curnode = newnode(st[prenode].cnt + val , 0 , 0);
		return;
	}
	int mid = l + r >> 1;
	if(idx <= mid){
		curnode = newnode(st[prenode].cnt + val , 0 , st[prenode].right);
		insert(st[curnode].left , st[prenode].left , l , mid , idx , val);
	}
	else{
		curnode = newnode(st[prenode].cnt + val , st[prenode].left , 0);
		insert(st[curnode].right , st[prenode].right , mid + 1 , r , idx , val);
	}
}
queue < int > que[N];
void build(){
	cur = 0;
	root[n + 1] = 0;
	for(int i = n ; i >= 1 ; --i){
		que[arr[i]].push(i);
		insert(root[i] , root[i + 1] , 1 , n , i , 1);
		if(que[arr[i]].size() > k){
			insert(root[i] , root[i] , 1 , n , que[arr[i]].front() , -1);
			que[arr[i]].pop();
		}
	}
}
int query(int l , int r , int rnode , int lnode , int ql , int qr){
	if(l > qr || r < ql || ql > qr){
		return 0;
	}
	if(l >= ql && r <= qr){
		return st[rnode].cnt - st[lnode].cnt;
	}
	int mid = l + r >> 1;
	return query(l , mid , st[rnode].left , st[lnode].left , ql , qr) + query(mid + 1 , r , st[rnode].right , st[lnode].right , ql , qr);
}
void solve(int l , int r){
	lastans = query(1 , n , root[l] , root[r + 1] , l , r);
	printf("%d\n" , lastans);
}
int main(){
	scanf("%d %d" , &n , &k);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	build();
	lastans = 0;
	scanf("%d" , &q);
	while(q--){
		scanf("%d %d" , &a , &b);
		int l = ((a + lastans) % n) + 1;
		int r = ((b + lastans) % n) + 1;
		if(l > r){
			swap(l , r);
		}
		solve(l , r);
	}
}