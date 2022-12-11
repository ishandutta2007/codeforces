#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int cnt[26];
int k;

int main(){

    string s;
    cin >> s;
    for(int j = 0;j<s.size();j++){
        cnt[s[j]-97]++;
    }
    for(int j = 0;j<26;j++){
        if(cnt[j]%2==1){
            k++;
        }
    }
    if(k == 0){
        cout << "First";
    }
    else if(k == 1){
        cout << "First";
    }
    else{
        if(k%2==0){
            cout << "Second";
        }
        else{
            cout << "First";
        }
    }
    return 0;
}