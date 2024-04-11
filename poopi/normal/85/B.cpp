										/* in the name of Allah */
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <memory.h>

using namespace std;

#define int64 long long

int n, k[3], tm[3];
int arr[100010];
priority_queue <int64> q[3];

int main(){
	while(cin >> k[0] >> k[1] >> k[2]){
		for(int i = 0; i < 3; i++)
			while(!q[i].empty())
				q[i].pop();
		cin >> tm[0] >> tm[1] >> tm[2] >> n;
		for(int i = 0; i < 3; i++){
			k[i] = min(k[i], n);
			for(int j = 0; j < k[i]; j++)
				q[i].push(0);
		}
		int64 mx = 0;
		for(int i = 0; i < n; i++){
			scanf("%d", &arr[i]);
			int64 end = arr[i];
			for(int j = 0; j < 3; j++){
				int64 t = -q[j].top();
				q[j].pop();
				t = max(t, end);
				end = t + tm[j];
				q[j].push(-end);
				//cout << end << ' ';
			}
			mx = max(mx, end - arr[i]);
			//cout << mx << endl;
		}
		cout << mx << endl;
	}
	return 0;
}