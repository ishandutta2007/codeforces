#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

	ll n;
	cin >> n;
	ll rs = 1;
	while(n>0){
        if(n-rs<=0){
            cout << n;
            break;
        }
        else{
            n-=rs;
        }
        rs++;
	}
	return 0;
}