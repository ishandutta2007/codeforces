#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    int n;
    cin >> n;
    int sk;
    bool s = false;
    for(int i = 0;i<n;i++){
        cin >> sk;
        if(sk == 1){
            s = true;
        }
    }
    if(s == true){
        cout << -1;
    }
    else{
        cout << 1;
    }
	return 0;
}