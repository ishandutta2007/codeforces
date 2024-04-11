#include <bits/stdc++.h>
#define ll long long

using namespace std;


string str;
int fr[26];

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, j;
    ios::sync_with_stdio(false);
    cin >> str;
    for(i = 0; i < str.size(); i++) {
        str[i] -= 'a';
        fr[str[i]]++;
    }
    i = 0;
    j = 25;
    while(i < j) {
        while(i < j && fr[i] % 2 == 0)
          i++;
        while(j > i && fr[j] % 2 == 0)
          j--;
        if(i < j) {
          fr[i]++;
          fr[j]--;
        }
    }
    i = 0;
    j = str.size() - 1;
    for(int ch = 0; ch < 26; ch++) {
        while(fr[ch] > 1) {
            fr[ch] -= 2;
            str[i] = ch + 'a';
            str[j] = ch + 'a';
            i++;
            j--;
        }
        if(fr[ch] == 1)
            str[str.size() / 2] = ch + 'a';
    }
    cout << str;
    //cin.close();
    //cout.close();
    return 0;
}