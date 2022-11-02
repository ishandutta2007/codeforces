#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#define inf (1 << 30)
using namespace std;

int main(){
    int n;
    cin >> n;
    int sum = n*n + 1;
    for(int i=0;i<n;i++){
        for(int j=1;j<=n/2;j++){
            cout << i*n/2+j << ' ' << sum - (i*n/2+j) << ' ';
        }
        cout << endl;
    }
    return 0;
}