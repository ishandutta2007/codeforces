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

const int maxn = 1 << 17;
bool f[maxn];
int d[maxn];
char dir[maxn];
int n;

int valid(int u ){
	if(u < 1 or u > n)
		return 3;
	else if(f[u] == true)
		return 2;
	return 1;
}

int main(){
	fastIO;
	cin >> n;
	for(int i = 1;i<=n;i++)
		cin >> dir[i];
	for(int i = 1;i<=n;i++)
		cin >> d[i];
	int k = 1;
	int p =0;
	while(valid(k) == 1){
		f[k] = true;
		if(dir[k] == '>'){
			k += d[k];
		}
		else{
			k -= d[k];
	
		}
	}
	cout << (valid(k) == 3 ? "FINITE": "INFINITE") << "\n";
	return 0;
}