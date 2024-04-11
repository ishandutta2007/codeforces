#include <bits/stdc++.h>


using namespace std;

string str1, str2;
string str;

int main() {
  //  fstream cin("A.in");
  //  ofstream cout("A.out");
    int i,n,j;
    char ch;
    ios::sync_with_stdio(false);
    cin >> str1;
    cin >> str2;
    cin >> str;
    for(i = 0; i < str.size(); i++) {
        if('a' <= str[i] && str[i] <= 'z')
            ch = str[i];
        else
            ch = str[i] - 'A' + 'a';
        int j = 0;
        while(j < 26 && str1[j] != ch)
            j++;
        if(j < 26){
        if('a' <= str[i] && str[i] <= 'z')
            str[i] = str2[j];
        else
            str[i] = str2[j] - 'a' + 'A';
        }
    }
    cout << str;
    //cin.close();
    //cout.close();
    return 0;
}