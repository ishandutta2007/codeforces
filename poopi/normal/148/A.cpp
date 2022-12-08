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
    /*string str;
    cin >> n >> str;
    for(int i = 1; i < n; i++)
        if(str[i] == str[i - 1])
            cnt++;*/
    int a[4];
    for(int i = 0; i < 4; i++)
        cin >> a[i];
    cin >> n;
    for(int i = 1; i <= n; i++){
        bool f = false;
        for(int j = 0; j < 4; j++)
            if(i % a[j] == 0)
                f = true;
        if(f) cnt++;
    }
    cout << cnt << endl;
    return 0;
}