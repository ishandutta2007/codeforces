                            /* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <set>
#include <fstream>
using namespace std;

#define int64 long long
#define P pair<int, int>
#define Max 1000010

int n, cnt;
int arr[Max];
int mat[110][110];
bool npr[Max];
set <int> st;
string str[100000];

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    int p;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> str[i];
    p = 0;
    while(p < str[0].length()){
        bool f = true;
        for(int i = 1; i < n; i++)
            if(str[i][p] != str[0][p])
                f = false;
        if(!f) break;
        p++;
    }
    cout << p << endl;
    return 0;
}