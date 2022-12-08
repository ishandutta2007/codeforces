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
int arr[200][2];

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    int t;
    string str;
    cin >> n >> t;
    cin >> str;
    for(int T = 0; T < t; T++){
        for(int i = 0; i + 1 < str.length(); i++)
            if(str[i] == 'B' && str[i + 1] == 'G')
                swap(str[i + 1], str[i++]);
    }
    cout << str << endl;
    return 0;
}