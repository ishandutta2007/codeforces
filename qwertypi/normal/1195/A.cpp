#include <iostream>
 
using namespace std;
int cnt[1001];
int main(){
	fill(cnt, cnt+1001, 0);
	int n, k;
	cin >> n >> k;
	for(int i=0;i<n;i++){
		int v;
		cin >> v;
		cnt[v]++;
	}
	int mod[2] = {0, 0};
	for(int i=1;i<=k;i++){
		mod[0] += cnt[i] / 2;
		mod[1] += cnt[i] % 2;
	}
	int k1 = (n+1) / 2;
	if(k1 < mod[0]){
		cout << k1 * 2;
	}else if(k1 < mod[0] + mod[1]){
		cout << mod[0] * 2 + (k1 - mod[0]);
	}else{
		cout << mod[0] * 2 + mod[1];
	}
	return 0;
}