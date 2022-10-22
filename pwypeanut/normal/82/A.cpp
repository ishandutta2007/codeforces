#include <iostream>
#include <cmath>
using namespace std;

int power[31];
bool exit = false;

void output(int x) {
     if ( x == 0 ) cout << "Sheldon" << endl;
     else if ( x == 1 ) cout << "Leonard" << endl;
     else if ( x == 2 ) cout << "Penny" << endl;
     else if ( x == 3 ) cout << "Rajesh" << endl;
     else cout << "Howard" << endl;
     exit = true;
}

int main() {
    for ( int i = 0; i < 31; i++ ) {
        power[i] = int(pow(2.0, i));
    }
    int n;
    cin >> n;
    int at = 0;
    for (int j = 0;; j++) {
        for ( int i = 0; i < 5; i++ ) {
            at += power[j];
            if ( n <= at ) output(i);
            if ( exit ) return 0;
        }
    }
    return 0;
}