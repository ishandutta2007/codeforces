#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string its(int sk){
    string re;
    while(sk > 0){

        re = char((sk % 10) + 48) + re;
        sk /= 10;
    }
    return re;
}

bool ir(int sk){
    string sks = its(sk);
    string paraugs = "1234567890";
    for(int i = 0;i<sks.size();i++){
        if(paraugs.find(sks[i]) == -1){
            return false;
        }
        else{
            paraugs.erase(paraugs.find(sks[i]),1);
        }
    }
    return true;
}

int main() {

	int n;
	cin >> n;
	n++;
	while(ir(n) == false){
	    n++;
	}
	cout << n;
	return 0;
}