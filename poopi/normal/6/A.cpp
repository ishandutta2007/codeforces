                            /* in the name of Allah */
#include <iostream>
#include <algorithm>
using namespace std;

int a[5];
int main(){
    for(int i = 0; i < 4; i++)
        cin >> a[i];
    sort(a, a + 4);
    if(a[0] + a[1] > a[2] || a[1] + a[2] > a[3])
        cout << "TRIANGLE" << endl;
    else if(a[0] + a[1] == a[2] || a[1] + a[2] == a[3])
        cout << "SEGMENT" << endl;
    else cout << "IMPOSSIBLE" << endl;
    return 0;
}