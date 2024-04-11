#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e6 + 9;
int f[N];

void init(){
	for(int i = 0;i<N;i++)f[i] = 1;
	for(int i = 2;i<N;i++){
		if(f[i] == 1)
		for(int j = 2;j * i < N;j++){
			f[i*j] = max(f[i*j],i);
		}
	}
}

int main(){
	fastIO;
	init();
	int x2;
	cin >> x2;
	int ans = (int)1e9;
	for(int i = x2-f[x2]+1;i<=x2;i++){
		if(f[i] == 1)
			continue;
		ans = min(ans,i-f[i]+1);
	}
	cout << ans;
	return 0;
}