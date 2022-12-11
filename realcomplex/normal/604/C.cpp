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

int main(){
	fastIO;
	int n;
	cin >> n;
	string a;
	cin >> a;
	int cnt = 1;
	for(int i = 1;i<n;i++){
		if(a[i]!=a[i-1])
			cnt++;
	}
	cout << min(cnt+2,n);
	return 0;
}