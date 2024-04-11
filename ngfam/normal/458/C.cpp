#include <bits/stdc++.h>

using namespace std;

const int N = 100001;

int n;
int pos[N];
vector < int > tickets[N];
priority_queue < int, vector < int >, greater < int > > heap;

int calc(int x){
	int ans = 0, cnt = 0;

	fill(pos, pos + N, 0);

	for(int i = 1; i < N; ++i){
		while(tickets[i].size() - pos[i] >= x){
			ans += tickets[i][pos[i]];
			++cnt;
			++pos[i];
		}
	}


	while(!heap.empty()){
		heap.pop();
	}


	for(int i = 0; i < N; ++i){
		for(int j = pos[i]; j < tickets[i].size(); ++j){
			heap.push(tickets[i][j]);
		}
	}


	while(cnt < x){
		++cnt;
		ans += heap.top();
		heap.pop();
	}

	return ans;

}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	scanf("%d", &n);

	long long tot = 0;

	for(int i = 1; i <= n; ++i){
		int x, c;
		scanf("%d%d", &x, &c);
		tickets[x].push_back(c);
		tot += c;
	}

	int low = 1, high = n - 1, ans = n;

	for(int i = 0; i < N; ++i){
		sort(tickets[i].begin(), tickets[i].end());
	}

	while(low <= high){
		int val = (low + high) >> 1;


		if(calc(val) < calc(val + 1)){
			ans = val;
			high = val - 1;
			tot = calc(val);
		}
		else{
			low = val + 1;
		}
	}	

	cout << tot;

	return 0;
}