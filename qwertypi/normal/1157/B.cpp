#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#define inf (1 << 30)
using namespace std;

int main(){
    int n;
    cin >> n;
    char s[200002];
    cin >> s;
    char m[10];
    for(int i=1;i<10;i++){
        cin >> m[i];
    }
    int start;
    for(int i=0;i<n;i++){
        if(m[s[i]-'0'] > s[i]){
            start = i;
            break;
        }
    }
    for(int i=start;i<n;i++){
        if(m[s[i]-'0'] >= s[i]){
            s[i] = m[s[i]-'0'];
        }else{
            break;
        }
    }
    cout << s;
    return 0;
}