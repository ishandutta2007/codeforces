                            /* in the name of Allah */
#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    string str, res;
    while(cin >> n){
        int mx = -100000;
        int a, b, c, s;
        for(int i = 0; i < n; i++){
            cin >> str >> a >> b;
            s = a * 100 - b * 50;
            for(int j = 0; j < 5; j++){
                cin >> c;
                s += c;
            }
            if(s > mx){
                mx = s;
                res = str;
            }
        }
        cout << res << endl;
    }
    return 0;
}