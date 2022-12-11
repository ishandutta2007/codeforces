#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

priority_queue<int>p;

int main(){
	int n;
	scanf("%i",&n);	
	int cur;
	ll ans = 0;
	for(int j = 0;j<n;j++){
		scanf("%i",&cur);
		p.push(-cur);
		p.push(-cur);
		ans += 1LL*(cur+p.top());
		p.pop();
	}
	printf("%I64d\n",ans);
	return 0;
}