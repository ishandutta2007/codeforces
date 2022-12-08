                            /* in the name of Allah */
#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

int dp[1000000];
char ch;

int main(){
    for(int i = 0; i < 10; i++)
        dp[i] = 0;
    for(int i = 10; i < 1000000; i++){
        int t = 0, n = i;
        while(n){
            t += n % 10;
            n /= 10;
        }
        dp[i] = dp[t] + 1;
    }
    int sum = 0, len = 0;
    while(cin >> ch){
        sum += ch - '0';
        len++;
    }
    if(len < 2)
        cout << dp[sum] << endl;
    else cout << dp[sum] + 1 << endl;
    return 0;
}