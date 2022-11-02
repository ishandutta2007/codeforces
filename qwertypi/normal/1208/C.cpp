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

#define p 1000000007

using namespace std;

typedef long long ll;
typedef long double ld;

int A[1000][1000];
int main(){
	int n;
	cin >> n;
	n /= 4;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int x=0;x<4;x++){
				for(int y=0;y<4;y++){
					A[i * 4 + x][j * 4 + y] = i * n * 16 + j * 16 + x * 4 + y;
				}
			}
		}
	}
	for(int i=0;i<n*4;i++){
		for(int j=0;j<n*4;j++){
			cout << A[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}