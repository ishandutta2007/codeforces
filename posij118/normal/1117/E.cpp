#include <bits/stdc++.h>
using namespace std;

int main(){
    string t, u, ans;
    cin >> u;

    string s1, s2, s3;
    int n, ii;
    n = u.size();
    bool is_same_char[n][n][2];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n;  j++){
            is_same_char[i][j][0] = 0;
            is_same_char[i][j][1] = 0;
        }
    }

    for(int i = 0; i<n; i++){
        ii = i;
        s1.push_back('a' + ii % 26);
        ii /= 26;
        s2.push_back('a' + ii % 26);
        ii /=26;
        s3.push_back('a' + ii % 26);
    }

    cout << "? " << s1 << endl;
    fflush(stdout);
    cin >> t;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(t[j] == s1[i]){
                if (!is_same_char[j][i][0]) is_same_char[j][i][0] = 1;
                else{
                    is_same_char[j][i][0] = 0;
                    is_same_char[j][i][1] = 1;
                }
            }
        }
    }

    cout << "? " << s2 << endl;
    fflush(stdout);
    cin >> t;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(t[j] == s2[i]){
                if (!is_same_char[j][i][0]) is_same_char[j][i][0] = 1;
                else{
                    is_same_char[j][i][0] = 0;
                    is_same_char[j][i][1] = 1;
                }
            }
        }
    }

    cout << "? " << s3 << endl;
    fflush(stdout);
    cin >> t;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(t[j] == s3[i]){
                if (!is_same_char[j][i][0]) is_same_char[j][i][0] = 1;
                else{
                    is_same_char[j][i][0] = 0;
                    is_same_char[j][i][1] = 1;
                }
            }
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(is_same_char[j][i][0] &&  is_same_char[j][i][1]) ans.push_back(u[j]);
        }
    }

    cout << "! " << ans;

}