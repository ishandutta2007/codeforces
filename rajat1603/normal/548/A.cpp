#include <bits/stdc++.h>
using namespace std;
string str;
int k;
int n;
bool check(string t){
    string::iterator start = t.begin();
    string::iterator finish = t.end();
    finish --;
    while(start < finish){
        if(*start != *finish){
            return 1;
        }
        ++start;
        --finish;
    }
    return 0;
}
int main(){
    cin >> str;
    cin >> k;
    n = str.size();
    if(n % k){
        cout << "NO";
    }
    else{
        int sz = n / k ;
        for(int i = 0 ; i < n ; i += sz){
            if(check(str.substr(i,sz))){
                cout << "NO";
                return 0;
            }
        }
        cout << "YES";
    }
}