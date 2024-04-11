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
	int q[n][n];
	int l = n/2,r= n/2;
	int p = 1;
	int k = 2;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++)
			q[i][j] = 0;
	}
	for(int i = 0;i<n;i++){
		if(i < n/2){
			for(int j = l;j<=r;j++){
				q[i][j] = p;
				p+=2;
			}
			l--;
			r++;
		}
		else{
			for(int j = l;j<=r;j++){
				q[i][j] = p;
				p+=2;
			}
			l++;
			r--;
		}
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++)
			if(q[i][j] == 0){
				q[i][j] = k;
				k+=2;
			}
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++)
			cout << q[i][j] << " ";
		cout << "\n";
	}
	return 0;
}