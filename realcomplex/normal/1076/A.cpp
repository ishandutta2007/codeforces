#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int p = n-1;
    for(int i = 0; i + 1 < n;i ++ ){
        if(s[i] > s[i + 1]){
            p = i;
            break;
        }
    }
    for(int x = 0; x < p; x ++ )
        cout << s[x];
    for(int j = p + 1; j < n; j ++ ){
        cout << s[j];
    }
    return 0;
}