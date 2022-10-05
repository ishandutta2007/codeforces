#include <iostream>
using namespace std;

int main(){
    int n, x;
    bool b = false;
    scanf("%d", &n);
    while (n--) scanf("%d", &x), b = b || (x & 1);
    cout << (b ? "First" : "Second") << endl;
}