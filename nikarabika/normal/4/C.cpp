#include <bits/stdc++.h>

using namespace std;

int n;
map <string, int> M;

int main(){
    cin >> n;
    for(int i = 0; i < n; i ++){
        string s;
        cin >> s;
        if(M[s] == 0)
            cout << "OK" << endl;
        else
            cout << s << M[s] << endl;
        M[s] ++;
    }
    return 0;
}