#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int lkd(int a,int b){
    if(b == 0){
        return a;
    }
    else{
        return lkd(b,a % b);
    }
}

int main() {

    int a,b,n;
    cin >> a >> b >> n;
    int g = 0;
    while(1){
        if(g == 0){
            if(n - lkd(a,n) >= 0){
                n -= lkd(a,n);
                g = 1;
            }
            else{
                cout << 1;
                break;
            }
        }
        else{
            if(n - lkd(b,n) >= 0){
                n -= lkd(b,n);
                g = 0;
            }
            else{
                cout << 0;
                break;
            }
        }
    }
	return 0;
}