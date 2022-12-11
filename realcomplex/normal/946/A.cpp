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
	int n;
	cin >> n;
	int k;
	int a=0,c=0;
	for(int i = 0;i<n;i++){
		cin >> k;
		if(k < 0)
			c += k;
		else
			a += k;
	}
	cout << a-c;
	return 0;
}