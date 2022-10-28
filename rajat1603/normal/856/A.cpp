#include "bits/stdc++.h"
using namespace std;
const int N = 1e2 + 2;
const int M = 1e6 + 6;
const int MIN = 1;
const int MAX = 1000000;
int t;
int n;
int arr[N];
vector < int > v;
int mark[M];
int tc;
int b[N];
int main(){
	scanf("%d" , &t);
	while(t--){
		scanf("%d" , &n);
		for(int i = 1 ; i <= n ; ++i){
			scanf("%d" , arr + i);
		}
		v.clear();
		sort(arr + 1 , arr + 1 + n);
		for(int i = 1 ; i < n ; ++i){
			for(int j = i + 1 ; j <= n ; ++j){
				v.emplace_back(arr[j] - arr[i]);
			}
		}
		++tc;
		bool rip = 0;
		int cur = 1;
		for(int i = 1 ; i <= n ; ++i){
			while(cur <= MAX && mark[cur] == tc){
				++cur;
			}
			if(cur > MAX){
				rip = 1;
				break;
			}
			b[i] = cur;
			for(int x : v){
				if(cur + x <= MAX){
					mark[cur + x] = tc;
				}
			}
			mark[cur] = tc;
		}
		if(rip){
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for(int i = 1 ; i < n ; ++i){
			printf("%d " , b[i]);
		}
		printf("%d\n" , b[n]);
	}
}