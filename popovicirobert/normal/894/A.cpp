#include <bits/stdc++.h>
#define lsb(x)

using namespace std;

string str;

int main(){
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, p;
    ios::sync_with_stdio(false);
    cin >> str;
    int ans = 0;
    for(i = 0; i + 2 < str.size(); i++) {
        for(j = i + 1; j + 1 < str.size(); j++)
            for(p = j + 1; p < str.size(); p++)
               if(str[i] == 'Q' && str[j] == 'A' && str[p] == 'Q')
                  ans++;
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}