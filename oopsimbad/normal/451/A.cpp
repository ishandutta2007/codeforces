#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    cout << (min(n,m) % 2 ? "Akshat" : "Malvika") << "\n";
    //int asdfhgjkl;
    //cin >> asdfhgjkl;
    return 0;
}