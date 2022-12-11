#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

int main(){

    bool p = true;
    int am = 0;
    stack<char>s;
    char k;
    while(cin >> k){
        if(k == '<' || k == '(' || k == '{' || k == '['){
            s.push(k);
        }
        else if(k == '>'){
            if(s.empty()){
                p = false;
            }
            else if(s.top() == '>' || s.top() == ')' || s.top() == '}' || s.top() == ']'){
                p = false;
            }
            else if(s.top() == '<'){
                s.pop();
            }
            else{
                am++;
                s.pop();
            }
        }
        else if(k == ')'){
            if(s.empty()){
                p = false;
            }
            else if(s.top() == '>' || s.top() == ')' || s.top() == '}' || s.top() == ']'){
                p = false;
            }
            else if(s.top() == '('){
                s.pop();
            }
            else{
                am++;
                s.pop();
            }
        }
        else if(k == '}'){
            if(s.empty()){
                p = false;
            }
            else if(s.top() == '>' || s.top() == ')' || s.top() == '}' || s.top() == ']'){
                p = false;
            }
            else if(s.top() == '{'){
                s.pop();
            }
            else{
                am++;
                s.pop();
            }
        }
        else{
            if(s.empty()){
                p = false;
            }
            else if(s.top() == '>' || s.top() == ')' || s.top() == '}' || s.top() == ']'){
                p = false;
            }
            else if(s.top() == '['){
                s.pop();
            }
            else{
                am++;
                s.pop();
            }
        }
    }
    if(p == false || !s.empty()){
        cout << "Impossible";
        return 0;
    }
    cout << am;
    return 0;
}