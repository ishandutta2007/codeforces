                            /* in the name of Allah */
#include <iostream>
#include <string>
using namespace std;

int a, b;
string str[2] = {"Ciel", "Hanako"};

int main(){
    cin >> a >> b;
    int t = 0;
    while(true){
        bool f = false;
        int s, str, end;
        if(t == 0)
            s = -1, str = 2, end = -1;
        else s = 1, str = 0, end = 3;
        for(int i = str; i != end; i += s){
            if(a >= i && b >= 22 - 10 * i){
                a -= i;
                b -= 22 - 10 * i;
                f = true;
                break;
            }
        }
        if(!f) break;
        t = 1 - t;
    }
    cout << str[1 - t] << endl;
    return 0;
}