 #include <iostream>
using namespace std;

int main() {
    long long int a, b, c;
    cin >> a >> b >> c;
    long long int ra, rb;
    if ( a % c == 0 ) ra = a / c;
    else ra = (a/c)+1;
    if ( b % c == 0 ) rb = b / c;
    else rb = (b/c)+1;
    cout << ra*rb << endl;
    return 0;
}