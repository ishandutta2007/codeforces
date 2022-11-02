#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    int a[10];
    fill(a, a + 10, 0);
    
    for(char c: s){
        if(c == 'L'){
            for(int i = 0; i<10; i++){
                if(!a[i]){
                    a[i] = 1;
                    break;
                }
            }
        }
        
        if(c == 'R'){
            for(int i = 0; i<10; i++){
                if(!a[9-i]){
                    a[9-i] = 1;
                    break;
                }
            }
        }
        
        else{
            a[c-'0'] = 0;
        }
    }
    
    for(int i = 0; i<10;i++){
        cout << a[i];
    }
    return 0;
}