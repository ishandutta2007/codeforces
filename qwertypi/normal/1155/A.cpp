#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    char s[300000];
    cin >> s;
    for(int i=0;i<n;i++){
        if(s[i-1] > s[i]){
            cout << "YES";
            cout << endl << i << ' ' << i+1;
            return 0;
        }
    }
    cout << "NO";
    cout << endl;
}