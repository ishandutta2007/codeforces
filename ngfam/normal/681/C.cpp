#include <bits/stdc++.h>
#define get get__

using namespace std;

priority_queue < int, vector < int >, greater < int > > heap;

char ins[11] = "insert";
char rem[11] = "removeMin";
char get[11] = "getMin";

typedef pair<int,int> ii;

vector < ii > ans;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif

	int n; scanf("%d", &n);

	for(int i = 1; i <= n; ++i){
		char ask[10];
		scanf("%s", ask);

		if(ask[0] == 'i'){
			int val; scanf("%d", &val);
			heap.push(val);

			ans.push_back(ii(0, val));
		}
		if(ask[0] == 'r'){
			if(heap.empty()){
				ans.push_back(ii(0, 1));	
			}
			else heap.pop();
			
			ans.push_back(ii(1, 0));
		}
		if(ask[0] == 'g'){
			int val; scanf("%d", &val);

			while(!heap.empty() && heap.top() < val){
			        ans.push_back(ii(1, 0));
				heap.pop();
			}

			if(heap.empty() || heap.top() != val){
				ans.push_back(ii(0, val));
				heap.push(val);
			}

			ans.push_back(ii(2, val));
		}
	}

	printf("%d\n", int(ans.size()));

	for(int i = 0; i < ans.size(); ++i){
		if(ans[i].first == 0){
			printf("%s %d\n", ins, ans[i].second);
		}                          
		if(ans[i].first == 1){
			printf("%s\n", rem);
		}
		if(ans[i].first == 2){
			printf("%s %d\n", get, ans[i].second);
		}
	}
	return 0;
}