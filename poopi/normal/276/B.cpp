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
#define Max 1000010

int n, cnt;
int arr[Max];
int mat[110][110];
bool npr[Max];
set <int> st;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    string str;
    cin >> str;
    for(int i = 0; i < str.length(); i++)
        arr[str[i] - 'a']++;
    for(int i = 0; i < 26; i++)
        cnt += arr[i] % 2;
    cout << (cnt == 0 || cnt % 2 ? "First" : "Second") << endl;
    return 0;
}