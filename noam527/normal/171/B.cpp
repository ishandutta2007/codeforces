#include <iostream>
using namespace std;
int main(){
    int n, output = 1; cin >> n;
    for (int i = 1; i < n; i++) output += 12 * i;
    cout << output << endl;
}