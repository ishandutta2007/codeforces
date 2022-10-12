#include<bits/stdc++.h>
using namespace std;

int main(){
    long n,l;
    string s,c;
    cin >> n;
    cin >> c;
    l = c.length();
    int i;
    bool sama;
    for (i=1; i<n; i++){
        cin >> s;

        for(int j=0; j<l; j++) {
            if (s.at(j) != '?' && c.at(j) == '?') c.at(j) = s.at(j);
            if (s.at(j) != c.at(j) && s.at(j) != '?') {c.at(j) = '-';}
        }
    }

    for(i=0; i<l; i++) {
        if (c.at(i) == '?') cout << "a";
        else if (c.at(i) == '-') cout << "?";
        else cout << c.at(i);
    }
    cout << endl;
    return 0;
}