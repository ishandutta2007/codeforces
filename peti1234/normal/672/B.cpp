#include <bits/stdc++.h>

using namespace std;
int t[31];
int main()
{
    int n;
    int db=0;
    string s;
    cin >> n;
    cin >> s;
    if (n>26){
        cout << -1;
        return 0;
    }
    for (int i=0; i<n; i++){
        t[s[i]-'a']++;
    }
    for (int i=0; i<31; i++){
        if (t[i]!=0){
            db+=t[i]-1;
        }
    }
    cout << db << endl;
    return 0;
}