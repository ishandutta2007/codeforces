#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s,s1;
    cin>>s>>s1;
    sort(s.begin(),s.end());
    if (s[0]=='0'){
    for (int i=0 ; i < s.length() ; i++){
        if ( s[i] != '0'){
            s[0]=s[i];
            s[i]='0';
            break;
        }

    }}
    if (s==s1){
        cout<<"OK";
    }
    else{
        cout<<"WRONG_ANSWER";
    }
}