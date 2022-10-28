#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const int SN = 1 << 19;
int n , k , d;
int arr[N];
int nxt[N];
pair < int , int > tmp[N];
int comp[N];
int start , ans;
void calc1(){
	nxt[n] = n;
	for(int i = n - 1 ; i >= 1 ; --i){
		if(d){
			if(((arr[i] % d) + d) % d == ((arr[i + 1] % d) + d) % d){
				nxt[i] = nxt[i + 1];
			}
			else{
				nxt[i] = i;
			}
		}
		else{
			if(arr[i] == arr[i + 1]){
				nxt[i] = nxt[i + 1];
			}
			else{
				nxt[i] = i;
			}
		}
	}
}
int freq[N];
void calc2(){
	int tot = 0;
	int ptr = 0;
	for(int i = 1 ; i <= n ; ++i){
		while(ptr + 1 <= n && tot + (freq[comp[ptr + 1]] == 0) == ptr + 1 - i + 1){
			tot += (++freq[comp[++ptr]]) == 1;
		}
		nxt[i] = min(nxt[i] , ptr);
		tot -= (--freq[comp[i]]) == 0;
	}
}
int segtree[SN];
int lazy[SN];
stack < int > s1 , s2;
void push(int l , int r , int node){
	if(lazy[node]){
		segtree[node] += lazy[node];
		if(l != r){
			lazy[node + node] += lazy[node];
			lazy[node + node + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}
void update(int l , int r , int node , int ql , int qr , int val){
	push(l , r , node);
	if(l > qr || r < ql || ql > qr){
		return;
	}
	if(l >= ql && r <= qr){
		lazy[node] += val;
		push(l , r , node);
		return;
	}
	int mid = l + r >> 1;
	update(l , mid , node + node , ql , qr , val);
	update(mid + 1 , r , node + node + 1 , ql , qr , val);
	segtree[node] = min(segtree[node + node] , segtree[node + node + 1]);
}
int query(int l , int r , int node , int ql , int qr){
	push(l , r , node);
	if(l > qr || r < ql || segtree[node] > k){
		return -1;
	}
	if(l == r){
		return r;
	}
	int mid = l + r >> 1;
	int res = query(mid + 1 , r , node + node + 1 , ql , qr);
	if(res == -1){
		res = query(l , mid , node + node , ql , qr);
	}
	return res;
}
int main(){
	scanf("%d %d %d" , &n , &k , &d);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
		tmp[i] = {arr[i] , i};
	}
	calc1();
	if(d == 0){
		start = 1;
		ans = 1;
		for(int i = 1 ; i <= n ; ++i){
			if(nxt[i] - i + 1 > ans){
				ans = nxt[i] - i + 1;
				start = i;
			}
		}
		printf("%d %d\n" , start , start + ans - 1);
		return 0;
	}
	sort(tmp + 1 , tmp + 1 + n);
	comp[tmp[1].second] = 1;
	for(int i = 2 ; i <= n ; ++i){
		comp[tmp[i].second] = comp[tmp[i - 1].second] + (tmp[i - 1].first != tmp[i].first);
	}
	calc2();
	for(int i = 1 ; i <= n ; ++i){
		if(arr[i] >= 0){
			arr[i] /= d;
		}
		else{
			arr[i] = -((-arr[i] + d - 1) / d);
		}
	}
	for(int i = n ; i >= 1 ; --i){
		int last = i + 1;
		while(!s1.empty() && arr[s1.top()] <= arr[i]){
			update(1 , n , 1 , last , s1.top() - 1 , -arr[last]);
			last = s1.top();
			s1.pop();
		}
		update(1 , n , 1 , last , (s1.empty()) ? n : (s1.top() - 1) , -arr[last]);
		last = i + 1;
		while(!s2.empty() && arr[s2.top()] >= arr[i]){
			update(1 , n , 1 , last , s2.top() - 1 , arr[last]);
			last = s2.top();
			s2.pop();
		}
		update(1 , n , 1 , last , (s2.empty()) ? n : (s2.top() - 1) , arr[last]);
		int mxnext , mnnext;
		if(s1.empty()){
			mxnext = n;
		}
		else{
			mxnext = s1.top() - 1;
		}
		if(s2.empty()){
			mnnext = n;
		}
		else{
			mnnext = s2.top() - 1;
		}
		s1.push(i);
		s2.push(i);
		update(1 , n , 1 , i + 1 , n , -1);
		update(1 , n , 1 , i , mxnext , arr[i]);
		update(1 , n , 1 , i , mnnext , -arr[i]);
		int r = query(1 , n , 1 , i , nxt[i]);
		if(r - i + 1 >= ans){
			start = i;
			ans = r - i + 1;
		}
	}
	printf("%d %d\n" , start , start + ans - 1);
}