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

const int N = (int)3e5 + 9;
ll x[N];
int main(){
	fastIO;
	int n;
	cin >> n;
	for(int i=  1;i<=n;i++){
		cin >> x[i];
	}
	sort(x+1,x+n+1);
	cout << x[(n+1)/2];
	return 0;
}