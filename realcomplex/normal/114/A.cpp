#include <bits/stdc++.h>
using namespace std;

int main() {
	
	long long a,b;
	cin >> a >> b;
	bool pakape = false;
	int i = 0;
	while(pow(a,i + 1) <= b){
		if(pow(a,i + 1) == b){
			cout << "YES" << endl << i;
			pakape = true;	
		}
		i++;
	}
	if(pakape == false){
		cout << "NO";
	}
	return 0;
}