#include <cstdio>
#include <iostream>

using namespace std;

const int N = 1e5 + 500;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

typedef long long int llint;

llint s,v1,v2,t1,t2,sl1,sl2;

int main(){
    cin >> s >> v1 >> v2 >> t1 >> t2;
    sl1 = s * v1 + 2 * t1;
    sl2 = s * v2 + 2 * t2;
    if(sl1 == sl2) {
        cout << "Friendship" << endl;
    }
    else if(sl1 < sl2){
        cout << "First" << endl;
    }
    else {
        cout << "Second" << endl;
    }
}