								/* in the name of Allah */
#include <iostream>
using namespace std;

int n, d;
int h[1010];

int main(){
	while(cin >> n >> d){
		int cnt = 0;
		for(int i = 0; i < n; i++){
			cin >> h[i];
			for(int j = 0; j < i; j++)
				if(abs(h[i] - h[j]) <= d)
					cnt += 2;
		}
		cout << cnt << endl;
	}
	return 0;
}