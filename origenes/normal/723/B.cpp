#include <iostream>
#include <string>
#include <cctype>
using namespace std;
string s;
int main(){
    int n;
    cin>>n>>s;
    bool new_word=true, in_parentheses=false;
    int len=0, cnt=0, tmp_len=0;
    for(int i=0; i<n; i++){
        if(isalpha(s.at(i))){
            if(new_word){
                new_word=false;
                if(in_parentheses) cnt++;
            }
            if(!in_parentheses) tmp_len++;
        }
        else if(s.at(i)=='_'){
            new_word=true;
            if(!in_parentheses){
                if(tmp_len>len) len=tmp_len;
                tmp_len=0;
            }
        }
        else if(s.at(i)=='('){
            new_word=true;
            if(tmp_len>len) len=tmp_len;
            tmp_len=0;
            in_parentheses=true;
        }
        else{
            new_word=true;
            in_parentheses=false;
        }
    }
    if(tmp_len) len=max(len, tmp_len);
    cout<<len<<' '<<cnt<<endl;
    return 0;
}