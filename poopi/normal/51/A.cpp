										/* in the name of Allah */
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int n;
char ch[1010][4];

bool eq(int a, int b){
	for(int s = 0; s < 4; s++){
		bool dif = false;
		for(int i = 0; i < 4; i++){
			if(ch[a][i] != ch[b][(i + s) & 3])
				dif = true;
		}
		if(!dif) return true;
	}
	return false;
}

int main(){
	char tmp;
	while(cin >> n){
		int cnt = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < 2; j++)
				cin >> ch[i][j];
			for(int j = 3; j >= 2; j--)
				cin >> ch[i][j];
			if(i < n - 1)
				cin >> tmp >> tmp;
			bool has = false;
			for(int j = 0; j < i; j++)
				if(eq(j, i))
					has = true;
			if(!has) cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}