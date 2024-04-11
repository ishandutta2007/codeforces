				/* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
using namespace std;

int n, m;
bool mark[1000010];

int norm(int idx){
	if(idx < 0) idx *= -1;
	idx = idx % (2 * n - 2);
	if(idx > n)
		idx = 2 * n - 2 - idx;
	return idx;
}

void dfs(int idx){
	mark[idx] = true;
	int t1 = norm(idx + 2 * m - 2);
	int t2 = norm(idx - 2 * m + 2);
	if(!mark[t1]) dfs(t1);
	if(!mark[t2]) dfs(t2);
}

int main(){
	while(cin >> n >> m){
		memset(mark, false, sizeof mark);
		if(m > n)
			swap(n, m);
		int cnt = 0;
		for(int i = 0; i < n; i++){
			if(!mark[i]){
				dfs(i);
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}