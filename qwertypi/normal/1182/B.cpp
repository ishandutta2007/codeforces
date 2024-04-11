#include <iostream>
#include <vector>
#include <utility>
using namespace std;
vector<pair<int, int>> pts;
int x_axis[500];
int y_axis[500];
char pic[500][500];
int main(){
	fill(x_axis, x_axis+500, 0);
	fill(y_axis, y_axis+500, 0);
	int n, m;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> pic[i];
		for(int j=0;j<m;j++){
			if(pic[i][j] == '*'){
				pts.push_back(pair<int, int>{i, j});
			}
		}
	}
	for(auto i:pts){
		x_axis[i.first]++;
		y_axis[i.second]++;
	}
	int max_x = -1;
	int ind_x = -1;
	int max_y = -1;
	int ind_y = -1;
	for(int i=0;i<n;i++){
		if(x_axis[i] > max_x){
			max_x = x_axis[i];
			ind_x = i;
		}
	}
	for(int i=0;i<m;i++){
		if(y_axis[i] > max_y){
			max_y = y_axis[i];
			ind_y = i;
		}
	}
	if(ind_x == 0 || ind_y == 0 || ind_x == n-1 || ind_y == m-1){
		cout << "NO";
		return 0;
	}
	for(auto i:pts){
		if(i.first != ind_x && i.second != ind_y){
			cout << "NO";
			return 0;
		}
	}
	int L = 0, U = 0, R = m-1, D = n-1;
	for(int i=ind_x+1;i<n;i++){
		if(pic[i][ind_y] == '.'){
			D = i-1;
			break;
		}
	}
	for(int i=ind_x-1;i>=0;i--){
		if(pic[i][ind_y] == '.'){
			U = i+1;
			break;
		}
	}
	for(int i=ind_y+1;i<m;i++){
		if(pic[ind_x][i] == '.'){
			R = i-1;
			break;
		}
	}
	for(int i=ind_y-1;i>=0;i--){
		if(pic[ind_x][i] == '.'){
			L = i+1;
			break;
		}
	}
	int total = R - L + D - U + 1;
	if(pts.size() != total || R == ind_y || L == ind_y || D == ind_x || U == ind_x){
		cout << "NO";
	}else{
		cout << "YES";
	}
}