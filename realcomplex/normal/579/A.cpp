#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second

int main() {

    int n;
    cin >> n;
    int need = 1;
    while(n>1){
        if(n%2 == 0){
            n/=2;
        }
        else{
            n/=2;
            need++;
        }
    }
    cout << need;
	return 0;
}