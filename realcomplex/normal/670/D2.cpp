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

const int N = (int)1e5 + 9;
ll A[N];
ll B[N];

int n;
ll k;
bool can(ll u){
	ll y;
	ll sum = k;
	for(int i = 1;i<=n;i++){
		y = A[i] * u;
		y -= B[i];
		if(y < 0)
			y = 0;
		sum -= y;
		if(sum < 0)
			return false;
	}
	return true;
}

int main(){
	fastIO;
	cin >> n >> k;
	for(int i = 1;i<=n;i++)
		cin >> A[i];
	for(int i = 1;i<=n;i++)
		cin >> B[i];
	ll l = 0,r = (ll)2000000007;
	ll c = 0;
	while(r-l>1){
		c = (l+r)/2;
		if(can(c))
			l=c;
		else
			r=c;
	}
	cout << l;
	return 0;
}