                            /* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <set>
using namespace std;

#define int64 long long
#define P pair<int, int>

int n, cnt;
int arr[210];
int mn, mx;
set <int> st;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    string str[4];
    for(int i = 0; i < 4; i++)
        cin >> str[i];
    string res = "NO";
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cnt = 0;
            for(int a = 0; a < 2; a++)
                for(int b = 0; b < 2; b++)
                    if(str[i + a][j + b] == '#')
                        cnt++;
            if(cnt != 2)
                res = "YES";
        }
    }
    cout << res << endl;
    return 0;
}