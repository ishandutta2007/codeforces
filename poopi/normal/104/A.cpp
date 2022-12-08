                            /* in the name of Allah */
#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

int dp[1000000];
char ch;

int main(){
    int n;
    while(cin >> n){
        if(n < 11 || n > 21)
            cout << 0 << endl;
        else if(n == 20)
            cout << 15 << endl;
        else cout << 4 << endl;
    }
    return 0;
}