#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 123456;
int r[N];
ll v[N];
bool vis[N];
int main(){
	int n;
	cin >> n;
	for(int j = 1;j<=n;j++) cin >> r[j];
	int t = 0;
	ll k = 0;
	int c = 0;
	for(int j = 1;j<=n;j++){
		if(!vis[j]){
			k = 0;
			c = j;
			while(!vis[c]){
				vis[c] = true;
				c = r[c];
				k++;
			}	
			v[t++]=k;
		}
	}
	sort(v,v+t);
	ll ans = 0;
	if(t>1){
		ans += (v[t-1]+v[t-2])*(v[t-1]+v[t-2]);
		t-=2;
	}
	for(int j = 0;j<t;j++){
		ans += (v[j]*v[j]);
	}
	cout << ans;
	return 0;
}