#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << n << endl;
        for(int i=1;i<=n;i++){
            cout << i << " ";
        }
        cout << "\n";
    }
}