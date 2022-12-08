                            /* in the name of Allah */
#include <iostream>
#include <string>

using namespace std;

int main(){
    string a, b, c;
    while(cin >> a >> b){
        c = a;
        for(int i = 0; i < a.length(); i++)
            c[i] = (a[i] == b[i] ? '0' : '1');
        cout << c << endl;
    }
    return 0;
}