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
    cin >> n;
    string str;
    cin >> str;
    for(int i = 0; i < str.length(); i++)
        arr[str[i] - 'a']++;
    for(int i = 0; i < 26; i++){
        if(arr[i] % n){
            cout << -1 << endl;
            return 0;
        }
        arr[i] /= n;
    }
    str = "";
    for(int i = 0; i < 26; i++)
        for(int j = 0; j < arr[i]; j++)
            str += (char)(i + 'a');
    for(int i = 0; i < n; i++)
        cout << str;
    cout << endl;
    return 0;
}