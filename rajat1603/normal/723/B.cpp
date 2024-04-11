#include "bits/stdc++.h"
using namespace std;
int ans1 = 0;
int ans2 = 0;
int n;
string str;
string cur;
int tmp;
int cnt;
int main(){
    cin >> n;
    cur = "";
    tmp = 0;
    cin >> str;
    for(char c : str){
        if(isalpha(c)){
            cur += c;
        }
        else if(c == '('){
            ans1 = max(ans1 , int(cur.size()));
            cur = "";
            tmp = 1;
            cnt = 0;
        }
        else if(c == ')'){
            tmp = 0;
            ans2 += cnt;
            if(cur.size()){
                ++ans2;
            }
            cur = "";
        }
        else{
            if(tmp){
                if(cur.size()){
                    ++cnt;
                }
                cur = "";
            }
            else{
                ans1 = max(ans1 , int(cur.size()));
                cur = "";
            }
        }
    }
    ans1 = max(ans1 , int(cur.size()));
    cout << ans1 << " " << ans2 << endl;
}