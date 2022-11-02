#include <iostream>

using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    for(int i=0;i<100000;i++){
        if(i * i + 3 * i == 2 * (n + k)){
            cout << n - i;
            return 0;
        }
    }
}