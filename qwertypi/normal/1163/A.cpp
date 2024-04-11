#include <iostream>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    if(m > n/2){
        cout << n - m;
    }else{
        cout << max(1, m);
    }
    return 0;
}