#include "bits/stdc++.h"
using namespace std;
int cnt1 = 0;
int cnt2 = 0;
string str;
int main(){
    cin >> str;
    for(char c : str){
        cnt1 += c - '0';
    }
    cnt1 += cnt1 & 1;
    cin >> str;
    for(char c : str){
        cnt1 -= c - '0';
    }
    puts(cnt1 >= 0 ? "YES" : "NO");
}