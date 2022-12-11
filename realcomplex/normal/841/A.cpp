#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

int b[26];

int main(){

    int n,k;
    cin >> n >> k;
    bool c = true;
    char s;
    for(int i = 0;i<n;i++){
        cin >> s;
        b[s-97]++;
    }
    for(int i = 0;i<26;i++){
        if(b[i] > k){
            c = false;
        }
    }
    if(c == false) cout << "No";
    else cout << "Yes";
    return 0;
}