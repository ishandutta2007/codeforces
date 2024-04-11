#include <iostream>
#include <string>

using namespace std;
string a;

int main(){
    cin >> a;
    cout << a;
    for(int i = a.size()-1;i>=0;i--){
        cout << a[i];
    }
    cout << endl;
}