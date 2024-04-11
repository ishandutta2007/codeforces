#include <bits/stdc++.h>
#define ll long long
#define lsb(x) (x & (-x))


using namespace std;


string str;


int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i;
    ios::sync_with_stdio(false);
    cin >> str;
    int cnt = 0;
    for(i = 0; i < str.size(); i++) {
        if(i + 4 < str.size()) {
            if(str[i] == 'D' && str[i + 1] == 'a' && str[i + 2] == 'n' && str[i + 3] == 'i' && str[i + 4] == 'l')
                cnt++;
        }
        if(i + 3 < str.size()) {
            if(str[i] == 'O' && str[i + 1] == 'l' && str[i + 2] == 'y' && str[i + 3] == 'a')
                cnt++;
        }
        if(i + 4 < str.size()) {
            if(str[i] == 'S' && str[i + 1] == 'l' && str[i + 2] == 'a' && str[i + 3] == 'v' && str[i + 4] == 'a')
                cnt++;
        }
        if(i + 2 < str.size()) {
            if(str[i] == 'A' && str[i + 1] == 'n' && str[i + 2] == 'n')
                cnt++;
        }
        if(i + 5 < str.size()) {
            if(str[i] == 'N' && str[i + 1] == 'i' && str[i + 2] == 'k' && str[i + 3] == 'i' && str[i + 4] == 't' && str[i + 5] == 'a')
                cnt++;
        }
    }
    if(cnt == 1)
        cout << "YES";
    else
        cout << "NO";
    //cin.close();
    //cout.close();
    return 0;
}