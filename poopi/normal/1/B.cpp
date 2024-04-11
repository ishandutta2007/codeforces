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

string toCh(int num){
    int p = 26, c = 1;
    while(num >= p){
        num -= p;
        p *= 26;
        c++;
    }
    string res;
    for(int i = 0; i < c; i++){
        res = (char)(num % 26 + 'A') + res;
        num /= 26;
    }
    return res;
}

int toN(string str){
    int res = 1, p = 26;
    for(int i = 1; i < str.length(); i++){
        res += p;
        p *= 26;
    }
    p = 1;
    for(int i = str.length() - 1; i >= 0; i--){
        res += p * (str[i] - 'A');
        p *= 26;
    }
    return res;
}

int main(){
    cin >> n;
    string str;
    for(int t = 0; t < n; t++){
        cin >> str;
        string s = str;
        for(int i = 0; i < s.length(); i++)
            if(s[i] >= 'A' && s[i] <= 'Z')
                s[i] = ' ';
        istringstream sin(s);
        int b = 0;
        while(sin >> arr[b])
            b++;
        if(b == 2)
            cout << toCh(arr[1] - 1) << arr[0] << endl;
        else{
            cout << 'R' << arr[0] << 'C';
            b = 0;
            while(str[b] >= 'A' && str[b] <= 'Z')
                b++;
            cout << toN(str.substr(0, b)) << endl;
        }
    }
    return 0;
}