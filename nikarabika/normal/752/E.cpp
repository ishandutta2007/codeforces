//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 1e6 + 85 - 69,
	  maxval = 1e7 + 10;
LL mp[maxval];
int a[maxn];
int n;
LL k;

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++)
		scanf("%d", a + i), mp[a[i]]++;
	LL sum = n,
	   mn = 1e9;
	LL ptr = 1e7 + 10,
	   hav = 0;
	for(int i = maxval * 2; i > 1; i--){
		if(i < maxval and mp[i]){
			mp[i>>1] += mp[i];
			mp[(i+1)>>1] += mp[i];
			if((i>>1) >= ptr) hav += mp[i];
			mp[i] = 0;
		}
		smin(mn, LL(i>>1));
		while(ptr > mn)
			hav += mp[--ptr];
		if(hav >= k){
			cout << ptr << '\n';
			return 0;
		}
	}
	if(sum >= k)
		cout << mn << '\n';
	else
		cout << -1 << '\n';
	return 0;
}