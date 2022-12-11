#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

	int n;
	cin >> n;
	if(n%2 == 1){
        cout << 0;
	}
	else{
        int w = n/2;
        if(n%4 == 0){
            cout << (w/2)-1;
        }
        else{
            cout << w/2;
        }
	}
	return 0;
}