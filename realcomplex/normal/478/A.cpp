#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    int a,b,c,d,e;
    cin >> a >> b >> c >> d >> e;
    if((a+b+c+d+e)%5!=0||(a+b+c+d+e)==0){
        cout << -1;
        return 0;
    }
    cout << (a+b+c+d+e)/5;
    return 0;
}