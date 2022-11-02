#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );
    int x, y;
    cin >> x >> y;
    int li[3] = {y, y, y};
    int wy=0;
    while( li[0] < x ) {
        li[0] = li[1]+li[2]-1;
        sort(li, li+3);
        wy++;
    }
    cout << wy;
    return 0;
}