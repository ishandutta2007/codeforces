#include <iostream>
#include <string>

using namespace std;

int main(){
    int T;
    cin >> T;
    for(int i=1;i<=T;i++){
        string s1;
        cin >> s1;
        if(s1.size()>10){
            cout << s1[0] << (int)s1.size()-2 << s1[s1.size()-1] << "\n";
        }
        else cout << s1 << "\n";
    }

    return 0;
}