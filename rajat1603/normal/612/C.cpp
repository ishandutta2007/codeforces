#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
char str[N];
int ans = 0;
int n;
stack < char > s;
map < char , char > m;
int main(){
    m[')'] = '(';
    m[']'] = '[';
    m['}'] = '{';
    m['>'] = '<'; 
    scanf("%s" , str);
    n = strlen(str);
    for(int i = 0 ; i < n ; ++i){
        if(m.find(str[i]) == m.end()){
            s.push(str[i]);
        }
        else{
            if(s.empty()){
                cout << "Impossible\n";
                return 0;
            }
            char temp = s.top();
            s.pop();
            if(temp != m[str[i]]){
                ++ans;
            }
        }
    }
    if(!s.empty()){
        cout << "Impossible\n";
    }
    else{
        cout << ans;
    }
}