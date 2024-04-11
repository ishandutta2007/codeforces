							/* in the name of Allah */
#include <iostream>
#include <string>
using namespace std;

int n;
int x[110], d[110];

int main(){
	while(cin >> n){
		string res = "NO";
		for(int i = 0; i < n; i++){
			cin >> x[i] >> d[i];
			for(int j = 0; j < i; j++)
				if(x[i] + d[i] == x[j] && x[j] + d[j] == x[i])
					res = "YES";
		}
		cout << res << endl;
	}
	return 0;
}