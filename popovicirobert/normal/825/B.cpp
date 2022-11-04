#include <bits/stdc++.h>


using namespace std;

string str[11];

int main() {
    //fstream cin("B.in");
    //ofstream cout("B.out");
    int i,j,n;
    ios::sync_with_stdio(false);
    for(i = 1; i <= 10; i++)
        cin >> str[i];
    for(i = 1; i <= 10; i++) {
        for(j = 0; j < 10; j++) {
            if(str[i][j] == '.') {
                str[i][j] = 'X';
                int cnt = 0;
                int l = i, c = j;
                while(l > 0 && str[l][c] == 'X') {
                    l--;
                    cnt++;
                }
                l = i + 1;
                while(l <= 10 && str[l][c] == 'X') {
                    cnt++;
                    l++;
                }
                if(cnt >= 5) {
                    cout << "YES";
                    return 0;
                }
                cnt = 0;
                l = i;
                while(c >= 0 && str[l][c] == 'X') {
                    c--;
                    cnt++;
                }
                c = j + 1;
                while(c < 10 && str[l][c] == 'X') {
                    c++;
                    cnt++;
                }
                if(cnt >= 5) {
                    cout << "YES";
                    return 0;
                }
                l = i;
                c = j;
                cnt = 0;
                while(l > 0 && c >= 0 && str[l][c] == 'X') {
                    l--;
                    c--;
                    cnt++;
                }
                l = i + 1;
                c = j + 1;
                while(l <= 10 && c < 10 && str[l][c] == 'X') {
                    l++;
                    c++;
                    cnt++;
                }
                if(cnt >= 5) {
                    cout << "YES";
                    return 0;
                }
                l = i;
                c = j;
                cnt = 0;
                while(l > 0 && c < 10 && str[l][c] == 'X') {
                    l--;
                    c++;
                    cnt++;
                }
                l = i + 1;
                c = j - 1;
                while(l <= 10 && c >= 0 && str[l][c] == 'X') {
                    l++;
                    c--;
                    cnt++;
                }
                if(cnt >= 5) {
                    cout << "YES";
                    return 0;
                }
                str[i][j] = '.';
            }
        }
    }
    cout << "NO";
   // cin.close();
   // cout.close();
    return 0;
}