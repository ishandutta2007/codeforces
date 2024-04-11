#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    //
    int reizes = (n / 2) - 1;
    if(n % 2 == 1){
        cout << "7";
        for(int i = 0;i<reizes;i++){
            cout << "1";
        }
    }
    else{
        for(int i = 0;i<n/2;i++){
            cout << "1";
        }
    }
    return 0;
}