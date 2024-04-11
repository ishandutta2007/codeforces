#include <bits/stdc++.h>
using namespace std;
typedef long long int li;
typedef pair<int,int> pi;
typedef pair<li,li> pl;
li n,i,j,h,w,sum[502][502],adj[502][502], adj1[502][502], r1, c1, r2, c2, k, ans;
char arr[502][502];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> h >> w;
	for (i=1; i<=h; i++){
		for (j=1; j<=w; j++){
			cin >> arr[i][j];
		}
	}
	for (i=1; i<h; i++){
		for (j=1; j<=w; j++){
			if (arr[i][j]=='.'&&arr[i+1][j]=='.') adj[i][j]=adj[i][j-1]+1;
			else adj[i][j]=adj[i][j-1];
		}
	}
	for (i=1; i<w; i++){
		for (j=1; j<=h; j++){
			if (arr[j][i]=='.'&&arr[j][i+1]=='.') adj1[j][i]=adj1[j-1][i]+1;
			else adj1[j][i]=adj1[j-1][i];
		}
	}
	for (i=2; i<=w; i++){
		if (arr[1][i-1]=='.'&&arr[1][i]=='.') sum[1][i]=sum[1][i-1]+1;
		else sum[1][i]=sum[1][i-1];
	}
	for (i=2; i<=h; i++){
		if (arr[i-1][1]=='.'&&arr[i][1]=='.') sum[i][1]=sum[i-1][1]+1;
		else sum[i][1]=sum[i-1][1];
	}
	for (i=2; i<=h; i++){
		for (j=2; j<=w; j++){
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+adj[i-1][j]-adj[i-1][j-1]+adj1[i][j-1]-adj1[i-1][j-1];
		}
	}
	cin >> n;
	for (k=0; k<n; k++){
		cin >> r1 >> c1 >> r2 >> c2;
		ans = sum[r2][c2];
		ans = ans-sum[r1-1][c2]-sum[r2][c1-1]+sum[r1-1][c1-1]-adj[r1-1][c2]+adj[r1-1][c1-1]-adj1[r2][c1-1]+adj1[r1-1][c1-1];
		cout << ans << "\n";
	}
}