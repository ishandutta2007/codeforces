#include "bits/stdc++.h"
using namespace std;
const int N = 5e5 + 5;
int n , m , p;
char arr[N];
char str[N];
int nxt[N];
int prv[N];
bool deleted[N];
int match[N];
int bit[N];
void update(int idx , int val){
	while(idx <= n){
		bit[idx] += val;
		idx += idx & -idx;
	}
}
int query(int idx){
	int res = 0;
	while(idx){
		res += bit[idx];
		idx -= idx & -idx;
	}
	return res;
}
int query(int l , int r){
	return query(r) - query(l - 1);
}
int getnext(int i){
	if(query(i + 1 , n) == 0){
		return -1;
	}
	if(!deleted[i + 1]){
		return i + 1;
	}
	int l = i + 1;
	int r = n;
	while(l < r){
		int mid = l + r >> 1;
		if(query(i + 1 , mid) > 0){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}
	return l;
}
int getprev(int i){
	if(query(1 , i - 1) == 0){
		return -1;
	}
	if(!deleted[i - 1]){
		return i - 1;
	}
	int l = 1;
	int r = i;
	while(l < r){
		int mid = l + r >> 1;
		if(query(mid , i - 1) == 0){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}
	return l - 1;
}
int main(){
	scanf("%d %d %d" , &n , &m , &p);
	scanf("%s" , arr + 1);
	scanf("%s" , str + 1);
	stack < int > s;
	for(int i = 1 ; i <= n ; ++i){
		if(arr[i] == '('){
			s.push(i);
		}
		else{
			match[s.top()] = i;
			match[i] = s.top();
			s.pop();
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		bit[i] = i & -i;
	}
	for(int i = 1 ; i <= m ; ++i){
		char type = str[i];
		if(type == 'L'){
			int tmp = getprev(p);
			if(tmp != -1){
				p = tmp;
			}
		}
		else if(type == 'R'){
			int tmp = getnext(p);
			if(tmp != -1){
				p = tmp;
			}
		}
		else{
			int l = min(p , match[p]);
			int r = max(p , match[p]);
			//cout << p << " " << l << " " << r << endl;
			if(query(1 , l - 1) + query(r + 1 , n) == 0){
				continue;
			}
			for(int i = l ; i <= r ; ){
				if(!deleted[i]){
					update(i , -1);
				}
				deleted[i] = 1;
				i = getnext(i);
				if(i == -1){
					break;
				}
			}
			int tmp = getnext(r);
			if(tmp != -1){
				p = tmp;
			}
			else{
				p = getprev(l);
			}
		}
		/*for(int i = 1 ; i <= n ; ++i){
			if(!deleted[i]){
				printf("%c" , arr[i]);
			}
			else{
				printf("X");
			}
		}
		printf("\n");*/
	}
	for(int i = 1 ; i <= n ; ++i){
		if(!deleted[i]){
			printf("%c" , arr[i]);
		}
	}
}