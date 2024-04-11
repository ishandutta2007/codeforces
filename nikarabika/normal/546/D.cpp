#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e6 + 10;
int v[maxn], s[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	for(int i = 2; i < maxn; i++){
		if(v[i] == 0)
			for(int j = i; j < maxn; j += i)
				v[j]++;
		else if(v[i] == 1)
			for(int j = i; j < maxn; j += i)
				s[j]++;
		s[i] += s[i - 1] + v[i];
	}
	int t;
	scanf("%d", &t);
	while(t--){
		int a, b;
		scanf("%d%d", &a, &b);
		cout << s[a] - s[b] << '\n';
	}
	return 0;
}