#include <cstdio>
#include <algorithm>
#include <iostream>

typedef long long int llint;

using namespace std;

const int N = 1e5 + 500;
const int INF = 0x3f3f3f3f;
const int off = 1<<18;
const int MOD = 1e9 + 7;

string s;
int sol = 0,pot = 1,cnt = 0,bla;

int main(){
    cin  >> bla >> s;
    reverse(s.begin(),s.end());
    int i = 0;
    while(i < s.size()){
        cnt = 0;
        while(i < s.size() && s[i] == '1'){
            cnt++;i++;
        }
        sol += pot * cnt;
        pot *= 10;
        i++;
    }
    cout << sol << endl;
}