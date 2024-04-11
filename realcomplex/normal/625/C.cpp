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

const int N = 505;
int t[N][N];

int main(){
	fastIO;
	int n,k;
	cin >> n >> k;
	int l = n-k;
	int v = n*n-l;
	t[1][k] = v;
	for(int j = k+1;j<=n;j++)
		t[1][j] = t[1][j-1]+1;
	++l;
	int s = v;
	for(int i = 2;i<=n;i++){
		v -= l;
		s += v;
		t[i][k] = v;
		for(int j = k+1;j<=n;j++)
			t[i][j] = t[i][j-1]+1;
	} 
	int r = 1;
	cout << s << "\n";
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(t[i][j] == 0)
				t[i][j] = r,r++;
			cout << t[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}