#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    string n;
    cin >> n;
    if(n[0] == '0'){
        cout << 4;
    }
    else{
        n = "0" + n;
        int last =((n[n.size() - 2] - 48) * 10) + (n[n.size() - 1] - 48);
        if(last % 4 == 0){
            cout << 4;
        }
        else if(last % 4 == 1){
            cout << 0;
        }
        else if(last % 4 == 2){
            cout << 0;
        }
        else{
            cout << 0;
        }
    }
	return 0;
}