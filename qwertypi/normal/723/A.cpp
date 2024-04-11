#include <iostream>
using namespace std;
int main(){
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    int median = a1 + a2 + a3 - max(a1, max(a2, a3)) - min(a1, min(a2, a3));
    cout << abs(a1-median) + abs(a2-median) + abs(a3-median);
    return 0;
}