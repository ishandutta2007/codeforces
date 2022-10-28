#include "bits/stdc++.h"
using namespace std;
const int N = 4e3 + 3;
int n;
int a[N];
int b[N];
int downzero;
int upzero;
int downnonzero;
int upnonzero;
int score;
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n + n ; ++i){
		scanf("%d.%d" , a + i , b + i);
	}
	for(int i = 1 ; i <= n ; ++i){
		if(b[i]){
			++downnonzero;
			score -= b[i];
		}
		else{
			++downzero;
		}
	}
	for(int i = n + 1 ; i <= n + n ; ++i){
		if(b[i]){
			++upnonzero;
			score += 1000 - b[i];
		}
		else{
			++upzero;
		}
	}
	while(score > 500){
		if(upnonzero && downzero){
			score -= 1000;
			--downzero;
			++upzero;
			--upnonzero;
			++downnonzero;
		}
		else{
			break;
		}
	}
	while(score < -500){
		if(downnonzero && upzero){
			score += 1000;
			--upzero;
			++downzero;
			--downnonzero;
			++upnonzero;
		}
		else{
			break;
		}
	}
	score = max(score , -score);
	printf("%d.%.3d\n" , score / 1000 , score % 1000);
}