						/* in the name of Allah */
#include <iostream>
using namespace std;

int n, o, e;

int main(){
	cin >> n;
	int cnt = 0, tmp;
	for(int i = 0; i < n; i++){
		cin >> tmp;
		if(tmp % 2){
			cnt++;
			o = i + 1;
		}
		else{
			cnt--;
			e = i + 1;
		}
	}
	cout << (cnt > 0 ? e : o) << endl;
	return 0;
}