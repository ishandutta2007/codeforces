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
    int k, a = 0;
    string str;
    cin >> n >> k;
    for(int j = 0; j < n; j++){
        cnt = 0;
        cin >> str;
        for(int i = 0; i < str.length(); i++)
            if(str[i] == '4' || str[i] == '7')
                cnt++;
        if(cnt <= k) a++;
    }
    cout << a << endl;
    return 0;
}