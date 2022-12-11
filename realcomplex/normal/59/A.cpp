#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fi first
#define se second

int main()
{
    string s;
    cin >> s;
    int l,u;
    l = 0;
    u = 0;
    for(int i = 0;i<s.size();i++){
        if(s[i] >= 97){
            l++;
        }
        else{
            u++;
        }
    }
    if(u > l){
        for(int i = 0;i<s.size();i++){
            if(s[i] >= 97){
                s[i]-=32;
            }
            cout << s[i];
        }
    }
    else{
        for(int i = 0;i<s.size();i++){
            if(s[i] <= 96){
                s[i]+=32;
            }
            cout << s[i];
        }
    }
    return 0;
}