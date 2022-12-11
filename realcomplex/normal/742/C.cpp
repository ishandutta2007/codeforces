#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))

const int N = 109;
int in[N];
int out[N];
bool vis[N];

int main(){
	fastIO;
	int n;
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> out[i];
		in[out[i]]++;
	}
	for(int i = 1;i<=n;i++){
		if(in[i] == 0){
			cout << -1 << "\n";
			return 0;
		}
	}
	int ans = 1;
	int k;
	int s;
	for(int i = 1;i<=n;i++){
		if(vis[i])
			continue;
		k = i;
		s = 0;
		while(!vis[k]){
			vis[k] = true;
			s++;
			k = out[k];
		}
		if(s%2==0)
			s/=2;
		ans = s * ans / __gcd(ans,s);
	}
	cout << ans << "\n";
	return 0;
}