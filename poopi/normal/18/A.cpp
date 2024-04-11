				/* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

#define P pair<int, int>

int n;
int len[110];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool amood(int dx1, int dy1, int dx2, int dy2){
	if((dx1 == 0 && dy2 == 0) || (dx2 == 0 && dy1 == 0))
		return true;
	if(dx1 == 0 || dx2 == 0)
		return false;
	return ((double)(dy1 * dy2) / (dx1 * dx2)) == -1;
}

bool isr(int x[3], int y[3]){
	for(int i = 0; i < 3; i++)
		for(int j = i + 1; j < 3; j++)
			if(x[i] == x[j] && y[i] == y[j])
				return false;
	int dx1 = x[0] - x[1];
	int dy1 = y[0] - y[1];
	int dx2 = x[0] - x[2];
	int dy2 = y[0] - y[2];
	if(dx1 * dy2 == dx2 * dy1)
		return false;
	for(int i = 0; i < 3; i++){
		dx1 = x[i] - x[(i+1)%3];
		dy1 = y[i] - y[(i+1)%3];
		dx2 = x[(i+1)%3] - x[(i+2)%3];
		dy2 = y[(i+1)%3] - y[(i+2)%3];
		if(amood(dx1, dy1, dx2, dy2))
			return true;
	}
	return false;
}

int main(){
	int x[3], y[3];
	for(int i = 0; i < 3; i++)
		cin >> x[i] >> y[i];
	if(isr(x, y))
		cout << "RIGHT" << endl;
	else{
		bool f = false;
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 4; j++){
				x[i] += dir[j][0];
				y[i] += dir[j][1];
				if(isr(x, y))
					f = true;
				x[i] -= dir[j][0];
				y[i] -= dir[j][1];
			}
		}
		cout << (f ? "ALMOST" : "NEITHER") << endl;
	}
	return 0;
}