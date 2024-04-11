#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string s;

int main(){
    cin >> s;
    long long int sol= 0;
    if((s[0]-'0') %4 == 0) sol++;
    for(int i = 1;i<s.size();i++){
        if((s[i]-'0') %4 == 0) sol++;
        if(((s[i]-'0') + 10*(s[i-1]-'0')) % 4 == 0){
            sol += (long long int)i;
        }
    }
    printf("%I64d\n",sol);
}