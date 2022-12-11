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
	int n,m;
	cin >> n >> m;
	int arr[n][m];
	int l[n][m];
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			cin >> arr[i][j];
			l[i][j] = i;
		}
	}
	for(int x = n-2;x>=0;x--){
		for(int r = 0;r<m;r++){
			if(arr[x][r] <= arr[x+1][r]){
				l[x][r] = l[x+1][r];
			}
		}
	}
	int p[n];
	for(int i = 0;i<n;i++){
		p[i] = 0;
		for(int j = 0;j<m;j++)
			p[i] = max(p[i],l[i][j]);
	}
	int q;
	cin >> q;
	int a,b;
	while(q--){
		cin >> a >> b;
		--a,--b;
		if(p[a] >= b){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}
	return 0;
}