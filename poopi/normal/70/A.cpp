                            /* in the name of Allah */
#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        int res = 1;
        for(int i = 1; i < n; i++)
            res = (res * 3) % 1000003;
        cout << res << endl;
    }
    return 0;
}