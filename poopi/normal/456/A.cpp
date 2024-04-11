#include<iostream>
#include<string>
using namespace std;

int n, a, b;

int main(){
    cin >> n;
    string res = "Poor Alex";
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        if(a != b)
            res = "Happy Alex";
    }
    cout << res << endl;
    return 0;
}