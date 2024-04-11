#include <iostream>
using namespace std;

int a[100];
int n, k;

int main() {
    cin >> n >> k;
    for ( int i = 0; i < n; i++ ) {
         cin >> a[i];
    }
    int bar = a[k-1];
    int nextR = 0;
    for ( int i = 0; i < n; i++ ) {
        if ( a[i] >= bar && a[i] > 0 ) nextR++;
    }
    cout << nextR << endl;
    return 0;
}