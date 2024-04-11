#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const int S = 305;
int n;
int type;
int s;
int sum1[N];
int cur;
int ans;
int what[N];
int mark1[N];
int mark2[N];
int val[N];
stack < int > stk;
int main(){
	scanf("%d" , &n);
	cur = -1;
	ans = 0;
	while(!stk.empty()){
		stk.pop();
	}
	stk.push(S);
	int last = 0;
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , &type);
		what[i] = type;
		if(type == 1){
			scanf("%d" , &s);
			while(!stk.empty() && stk.top() < s){
				++ans;
				stk.pop();
			}
			last = s;
		}
		else if(type == 2){
			if(cur != -1){
				++mark2[cur];
				--mark2[i];
			}
		}
		else if(type == 3){
			scanf("%d" , &s);
			if(s < last){
				++ans;
			}
			else{
				stk.push(s);
			}
		}
		else if(type == 4){
			cur = -1;
		}
		else if(type == 5){
			stk.push(S);
		}
		else{
			if(cur == -1){
				cur = i;
			}
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		mark2[i] += mark2[i - 1];
		if(what[i] == 6){
			if(mark2[i]){
				++ans;
			}
		}
	}
	printf("%d\n" , ans);
}