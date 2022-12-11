#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    ll a,m;
    cin >> a >> m;
    ll produce = a;
    bool stop = false;
    for(int i = 0;i<100000;i++){
        produce += produce % m;
        if(produce % m == 0){
            stop = true;
            break;
        }
    }
    if(stop == false){
        cout << "No";
    }
    else{
        cout <<"Yes";
    }
	return 0;
}