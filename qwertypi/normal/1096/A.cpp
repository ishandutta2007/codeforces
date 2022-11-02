#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#define inf (1 << 30)
using namespace std;

int main(){
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int x, y;
        cin >> x >> y;
        cout << x << ' ' << x*2 << endl;
    }
    return 0;
}