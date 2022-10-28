#include "bits/stdc++.h"
using namespace std;
string str;
long long ans;
int dig;
long long decimalpt;
void solve(int s , int e){
    string cur = "";
    for(int i = s ; i <= e ; ++i){
        cur += str[i];
    }
    int num;
    if(cur.size() >= 3 && cur[cur.size() - 3] == '.'){
        num = cur.size() - 4;
    }
    else{
        num = cur.size() - 1;
    }
    long long val = 0;
    for(int i = 0 ; i <= num ; ++i){
        if(isdigit(cur[i])){
            val *= 10;
            val += cur[i] - '0';
        }
    }
    ans += val;
    val = 0;
    for(int i = num + 2 ; i < cur.size() ; ++i){
        val *= 10;
        val += cur[i] - '0';
    }
    decimalpt += val;
}
void print(){
    ans += decimalpt / 100;
    decimalpt %= 100;
    if(ans){
        int cur = 0;
        vector < char > v;
        v.clear();
        while(ans){
            v.push_back('0' + (ans % 10));
            ans /= 10;
            ++cur;
            if(cur == 3 && ans){
                cur = 0;
                v.push_back('.');
            }
        }
        reverse(v.begin() , v.end());
        for(auto it : v){
            cout << it;
        }
    }
    else{
        cout << "0";
    }
    if(decimalpt >= 10){
        cout << "." << decimalpt;
    }
    else if(decimalpt >= 1){
        cout << ".0" << decimalpt;
    }
    cout << endl;
}
int main(){
    cin >> str;
    ans = 0;
    decimalpt = 0;
    for(int i = 0 ; i < str.size() ; ++i){
        if(isdigit(str[i])){
            bool rekt = 0;
            for(int j = i ; j < str.size() ; ++j){
                if(isalpha(str[j])){
                    solve(i , j - 1);
                    i = j - 1;
                    rekt = 1;
                    break;
                }
            }
            if(!rekt){
                solve(i , int(str.size()) - 1);
                break;
            }
        }
    }
    print();
}