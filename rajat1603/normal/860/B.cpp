#include "bits/stdc++.h"
using namespace std;
const int N = 7e4 + 4;
const int SN = N * 50;
int n;
char str[N][11];
int child[SN][10];
int tot[SN];
int cur;
void insert(char str[] , int idx){
	int node = 1;
	for(int i = idx ; i < 9 ; ++i){
		int dig = str[i] - '0';
		if(!child[node][dig]){
			child[node][dig] = ++cur;
		}
		node = child[node][dig];
		++tot[node];
	}
}

void erase(char str[] , int idx){
	int node = 1;
	for(int i = idx ; i < 9 ; ++i){
		int dig = str[i] - '0';
		node = child[node][dig];
		--tot[node];
	}	
}

void reinsert(char str[] , int idx){
	int node = 1;
	for(int i = idx ; i < 9 ; ++i){
		int dig = str[i] - '0';
		node = child[node][dig];
		++tot[node];
	}
}

void insert(char str[]){
	for(int i = 0 ; i < 9 ; ++i){
		insert(str , i);
	}
}

int go(char str[] , int idx){
	int node = 1;
	for(int i = idx ; i < 9 ; ++i){
		int dig = str[i] - '0';
		if(!child[node][dig]){
			return i;
		}
		node = child[node][dig];
		if(!tot[node]){
			return i;
		}
	}
	return N;
}
void query(char str[]){
	for(int i = 0 ; i < 9 ; ++i){
		erase(str , i);
	}
	int ql = 0;
	int qr = 8;
	for(int i = 0 ; i < 9 ; ++i){
		int tmp = go(str , i);
		if(tmp - i < qr - ql){
			ql = i;
			qr = tmp;
		}
	}
	for(int i = 0 ; i < 9 ; ++i){
		reinsert(str , i);
	}
	for(int i = ql ; i <= qr ; ++i){
		printf("%c" , str[i]);
	}
	printf("\n");
}
int main(){
	scanf("%d" , &n);
	cur = 1;
	for(int i = 1 ; i <= n ; ++i){
		scanf("%s" , str[i]);
		insert(str[i]);
	}
	for(int i = 1 ; i <= n ; ++i){
		query(str[i]);
	}
}