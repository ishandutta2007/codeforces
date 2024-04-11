                            /* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <ctime>
#include <set>
using namespace std;

#define int64 long long
#define P pair<int, int>

int n, cnt;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    string str;
    cin >> n >> str;
    for(int i = 1; i < n; i++)
        if(str[i] == str[i - 1])
            cnt++;
    cout << cnt << endl;
    return 0;
}