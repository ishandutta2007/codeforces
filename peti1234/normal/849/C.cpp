#include <bits/stdc++.h>

using namespace std;
int k;
int main()
{
    cin >> k;
    string s;
    if (k==0) {
        cout << "abc";
        return 0;
    }
    s[0]='a';
    while (k>0){
        int i=0;
        while (k>=i) {
            k-=i;
            cout << s[0];
            i++;
        }
        s[0]++;
    }
    return 0;
}