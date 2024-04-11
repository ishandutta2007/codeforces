#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    for (int i = 0 ; i < n; ++i){
        int a;
        cin >> a;
        cout << a - 1 + a % 2 << " ";
    }
    return 0;
}