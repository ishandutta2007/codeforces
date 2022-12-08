										/* in the name of Allah */
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define int64 long long
#define P pair<int, int>

int64 X1, Y1;
int64 A, B;
int64 x, y;

int main(){
	while(cin >> X1 >> Y1){
		cin >> A >> B >> x >> y;
		string res = "NO";
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				if(x == 0 && y == 0){
					if(X1 == A && Y1 == B)
						res = "YES";
				}
				else{
					bool good = true;
					int64 c1 = A - X1;
					int64 c2 = B - Y1;
					int64 soor = c1 * x + c2 * y;
					int64 makh = x * x + y * y;
					if(soor % makh)
						good = false;
					int64 a = soor / makh;
					if(y == 0){
						soor = c2;
						makh = -x;
					}
					else{
						soor = c1 - a * x;
						makh = y;
					}
					if(soor % makh)
						good = false;
					int64 b = soor / makh;
					if(good){
						res = "YES";
						//cout << X1 << ' ' << Y1 << ' ' << A << ' ' << B << endl;
						//cout << x << ' ' << y << ' ' << a << ' ' << b << endl;
						//cout << endl;
					}
				}
				swap(A, B);
				A *= -1;
			}
			swap(X1, Y1);
			X1 *= -1;
		}
		cout << res << endl;
	}
	return 0;
}