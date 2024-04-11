#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        stack<int> s1;
        stack<int> s2;
        string s;
        cin >> s;
        int sum = 0;
        for(int i=0;i<(int)s.size();i++){
            if(s[i] == '(') s1.push(1);
            if(s[i] == '[') s2.push(1);
            if(s[i] == ')'){
                if(!s1.empty()){
                    s1.pop();
                    sum++;
                }
            }
            if(s[i] == ']'){
                if(!s2.empty()){
                    s2.pop();
                    sum++;
                }
            }
        }

        printf("%d\n", sum);
    }
}