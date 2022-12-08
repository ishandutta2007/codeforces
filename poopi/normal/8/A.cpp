                /* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string str[4] = {"fantasy", "backward", "forward", "both"};

int fun(string s1, string s2, string s3){
    int p = 0;
    while(p + s2.length() <= s1.length()){
        bool f = true;
        for(int i = 0; i < s2.length(); i++)
            if(s1[i + p] != s2[i])
                f = false;
        if(f) break;
        p++;
    }
    p += s2.length();
    if(p > s1.length())
        return 0;
    while(p + s3.length() <= s1.length()){
        bool f = true;
        for(int i = 0; i < s3.length(); i++)
            if(s1[i + p] != s3[i])
                f = false;
        if(f) break;
        p++;
    }
    p += s3.length();
    return (p <= s1.length() ? 1 : 0);
}

int main(){
    string s0, s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    s0 = s1;
    reverse(s0.begin(), s0.end());
    cout << str[fun(s1, s2, s3) * 2 + fun(s0, s2, s3)] << endl;
    return 0;
}