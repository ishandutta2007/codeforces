#include <bits/stdc++.h>
#define ll long long
using namespace std;
int cnt,grid[600][600];

int up(int r, int c){
	if (grid[r][c]==0){
		return 0;
	}
	return 1+up(r+1,c);
	
	
}
int down(int r, int c){
	if (grid[r][c]==0){
		return 0;
	}
	return 1+down(r-1,c);
	
	
}
int left(int r, int c){
	if (grid[r][c]==0){
		return 0;
	}
	return 1+left(r,c-1);
	
	
}
int right(int r, int c){
	if (grid[r][c]==0){
		return 0;
	}
	return 1+right(r,c+1);
	
	
}
int main (){
	ll r,c;
	cin >> r>>c;
	for (int i = 1; i <=r; i++){
		for (int j=1;j<=c;j++){
			char k;
			cin >> k;
			if (k=='*'){
				grid[i][j]=1;
				cnt++;
			}
			
		}
	}
	//if (cnt==0){
		//cout << "NO\n";
		//return 0;
	//}
	for (int i = 1; i <=r; i++){
		for (int j=1;j<=c;j++){
			if (grid[i][j]==1 and grid[i-1][j]==1 and grid[i+1][j]==1 and grid[i][j+1]==1 and grid[i][j-1]==1){
				int u=1;
				u+=up(i+1,j);
				u+=down(i-1,j);
				u+=left(i,j-1);
				u+=right(i,j+1);
				if (u==cnt){
					cout << "YES\n";
					return 0;
				}
			}
			
		}
	}
	
	cout << "NO\n";
		
	
}