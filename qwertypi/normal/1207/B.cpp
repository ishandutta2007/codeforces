#include <iostream>
#include <vector>
#include <utility>

#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define fi first
#define se second

#define p1 1000000007

using namespace std;

typedef long long ll;

int A[50][50];
int B[50][50];

vpii ans;
void f(int x, int y){
	ans.push_back(pii {x+1, y+1});
	B[x][y] = B[x][y+1] = B[x+1][y] = B[x+1][y+1] = 1;
}

int main(){
	for(int i=0;i<50;i++){
		fill(B[i], B[i]+50, 0);
	}
	int n, m;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> A[i][j];
		}
	}
	for(int i=0;i<n-1;i++){
		for(int j=0;j<m-1;j++){
			if(A[i][j] && A[i+1][j] && A[i][j+1] && A[i+1][j+1]){
				f(i, j);
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(A[i][j] != B[i][j]){
				cout << -1;
				return 0;
			}
		}
	}
	cout << ans.size() << endl;
	for(auto i:ans){
		cout << i.fi << ' ' << i.se << endl;
	}
	return 0;
}