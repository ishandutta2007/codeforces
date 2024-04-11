#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    int c[4];
    cin >> c[0] >> c[1] >> c[2] >> c[3];
    sort(c,c+4);
    int e = 1;
    for(int y = 1;y<4;y++){
        if(c[y] != c[y-1]){
            e++;
        }
    }
    cout << 4-e;
    return 0;
}