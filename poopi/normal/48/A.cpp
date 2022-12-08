#include <iostream>
#include <string>

using namespace std;

char o[3] = {'F', 'M', 'S'};
char g[3] = {'r', 's', 'p'};
int num[3];

int main(){
	string a[3];
	while(cin >> a[0] >> a[1] >> a[2]){
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 3; j++)
				if(a[j][0] == g[i])
					num[j] = i;
		bool fl = false;
		for(int i = 0; i < 3; i++){
			int j = (i + 1) % 3, k = (i + 2) % 3;
			int nex = (num[i] + 1) % 3;
			if(num[j] == nex && num[k] == nex){
				fl = true;
				cout << o[i] << endl;
				break;
			}
		}
		if(!fl)
			cout << '?' << endl;
	}
	return 0;
}