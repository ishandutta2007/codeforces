#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

string s;
int k,n;

int main(){
    cin >> n >>k >> s;
    string s1 = "";
    for(int i = 0;i<s.size();i++){
        int z = s[i]-'a';
        if(k < max(z,26-z)){
            if(z+k < 26){
                s1 += 'a' + (z+k);
                k-=k;
            }
            else{
                s1 += 'a' + (z-k);
                k-=k;
            }
        }
        else if(26-z > z){
            s1 += 'z';
            k -= (26-z-1);
        }
        else{
            s1 += 'a';
            k -= (z);
        }
    }
    if(k != 0){
        cout << -1 << endl;
    }
    else{
        cout << s1 << endl;
    }
}