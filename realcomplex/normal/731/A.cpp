#include <bits/stdc++.h>

using namespace std;

int dis(char a,char b){
    int c1,c2;
    c1 = 0;
    c2 = 0;
    char s = a;
    while(s!=b){
        s++;
        c1++;
        if(s>'z'){
            s = 'a';
        }
        if(s<'a'){
            s = 'z';
        }
    }
    s = a;
    while(s!=b){
        s--;
        c2++;
        if(s>'z'){
            s = 'a';
        }
        if(s<'a'){
            s = 'z';
        }
    }
    return min(c1,c2);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    cin >> s;
    int rez = 0;
    char c = 'a';
    for(int j = 0;j<s.size();j++){
        rez += dis(c,s[j]);
        c = s[j];
    }
    cout << rez;
    return 0;
}