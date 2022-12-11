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

const int N = 1005;
int A[N];
int B[N];

int n,k;
bool can(int u){
	int y;
	int sum = 0;
	for(int i = 1;i<=n;i++){
		y = A[i] * u;
		y -= B[i];
		if(y < 0)
			y = 0;
		sum += y;
	}
	return sum <= k;
}

int main(){
	fastIO;
	cin >> n >> k;
	for(int i = 1;i<=n;i++)
		cin >> A[i];
	for(int i = 1;i<=n;i++)
		cin >> B[i];
	int l = 0,r = 4009;
	int c = 0;
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