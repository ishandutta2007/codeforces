							/* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;


int n;

int main(){
	int res = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		int t = i, cnt = 0;
		for(int j = 2; t > 1 && j <= i; j++){
			if(t % j == 0){
				cnt++;
				while(t % j == 0)
					t /= j;
			}
		}
		if(cnt == 2)
			res++;
	}
	cout << res << endl;
	return 0;
}