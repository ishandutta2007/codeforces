#include "bits/stdc++.h"
using namespace std;
const int N = 1005;
int n;
int x[N];
int y[N];
/*
map < int , int > mx;
map < int , int > my;
int curx = 0;
int cury = 0;
int arr[N][N];
bool water[N][N];*/
int ans = 0;
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n + 1 ; ++i){
		scanf("%d %d" , x + i , y + i);
		//mx[x[i]];
		//my[y[i]];
	}
	/*
	for(auto &it : mx){
		it.second = ++curx;
	}
	for(auto &it : my){
		it.second = ++cury;
	}
	for(int i = 1 ; i <= n + 1 ; ++i){
		x[i] = mx[x[i]];
		y[i] = my[y[i]];
	}
	x[n + 2] = x[2];
	y[n + 2] = y[2];
	for(int i = 2 ; i <= n + 1 ; ++i){
		if(x[i] == x[i - 1]){
			for(int j = min(y[i - 1] , y[i]) ; j < max(y[i - 1] , y[i]) ; ++j){
				++arr[j][x[i]];
				cout << x[i] << " : " << j << endl;
			}
		}
		else{
			for(int j = min(x[i - 1] , x[i]) ; j < max(x[i - 1] , x[i]) ; ++j){
				++arr[y[i]][j];
				cout << j << " " << y[i] << endl;
			}	
		}
	}
	for(int i = 1 ; i <= cury ; ++i){
		for(int j = 1 ; j <= curx ; ++j){
			arr[i][j] += arr[i][j - 1];
		}
	}
	for(int i = 1 ; i <= cury ; ++i){
		for(int j = 1 ; j <= curx ; ++j){
			if((arr[i][j] & 1) && ((arr[i][curx] - arr[i][j]) & 1)){
				water[i][j] = 1;
				cout << j << " " << i << endl;
			}
		}
	}
	for(int i = 2 ; i <= n + 1 ; ++i){
		int dx = x[i];
		int dy = y[i];
		if(dx == x[i - 1]){
			if(dy < y[i - 1]){
				--dy;
			}
		}
		else{
			if(dx < x[i - 1]){
				--dx;
			}
		}
		cout << i << " " << x[i] << " " << y[i] << " " << dx << " " << dy << " " << water[dx][dy] << endl;
		ans += water[dx][dy];
	}*/
	//1 = right  , 2 = down , 3 = left , 4 = up
	/*int dir;
	if(x[3] > x[2]){
		dir = 1;
	}
	else{
		dir = 3;
	}
	for(int i = 2 ; i <= n ; ++i){
		int tmp;
		if(x[i] == x[i - 1]){
			if(x[i + 1] > x[i]){
				tmp = 1;
			}
			else{
				tmp = 3;
			}
		}
		else{
			if(y[i + 1] > y[i]){
				tmp = 4;
			}
			else{
				tmp = 2;
			}
		}
		ans += (tmp == dir);
		cout << tmp << " " << dir << endl;
		if(x[i] == x[i - 1]){
			if(y[i] > y[i - 1]){
				dir = 2;
			}
			else{
				dir = 4;
			}
		}
		else{
			if(x[i] > x[i - 1]){
				dir = 3;
			}
			else{
				dir = 1;
			}
		}
	}*/
	//1 = right  , 2 = down , 3 = left , 4 = up
	for(int i = 2 ; i <= n ; ++i){
		int prv;
		int cur;
		if(x[i] == x[i - 1]){
			if(y[i] > y[i - 1]){
				prv = 4;
			}
			else{
				prv = 2;
			}
		}
		else{
			if(x[i] > x[i - 1]){
				prv = 1;
			}
			else{
				prv = 3;
			}
		}
		if(x[i + 1] == x[i]){
			if(y[i + 1] > y[i]){
				cur = 4;
			}
			else{
				cur = 2;
			}
		}
		else{
			if(x[i + 1] > x[i]){
				cur = 1;
			}
			else{
				cur = 3;
			}
		}
		//up - right , right - down , down - left , left - up
		if(prv == 4 && cur == 1){

		}
		else if(prv == 1 && cur == 2){

		}
		else if(prv == 2 && cur == 3){

		}
		else if(prv == 3 && cur == 4){

		}
		else{
			++ans;
		}
	}
	printf("%d\n" , ans);
}