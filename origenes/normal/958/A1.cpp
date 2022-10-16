#include<iostream>
using namespace std;

int n;
string s1[15], s2[15];

void flipud() {
    int l = 0, r = n - 1;
    while(l < r) {
        for(int i = 0; i < n; i++) swap(s1[l][i], s1[r][i]);
        l++; r--;
    }
}

void fliplr() {
    int l = 0, r = n - 1;
    while(l < r) {
        for(int i = 0; i < n; i++) swap(s1[i][l], s1[i][r]);
        l++; r--;
    }
}

bool check() {
    for(int i = 0; i < n; i++)
        if(s1[i] != s2[i]) return false;
    return true;
}

void rotate() {
    string s[15];
    for(int i = 0; i < n; i++) s[i] = s1[i];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) s1[i][j] = s[j][n - 1 - i];
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> s1[i];
    for(int i = 0; i < n; i++) cin >> s2[i];

    /*for(int i = 0; i < 4; i++) {
        for(int j = 0; j < n; j++) cout << s1[j] << endl;
        cout << endl << endl;
        rotate();
    }*/

    /*for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                if(check()) { cout << "Yes\n"; return 0; }

                if(j == 0 && k == 0) {
                    for(int o = 0; o < n; o++)
                        cout << s1[o] << endl;
                    cout << endl << endl;
                }


                fliplr();
            }
            flipud();
        }
        rotate();
    }*/

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 4; k++) {
                if(check()) { cout << "Yes\n"; return 0; }

                //for(int o = 0; o < n; o++) cout << s1[i] << endl;
                //cout << endl << endl;


                rotate();
            }
            fliplr();
        }
        flipud();
    }
    cout << "No\n";
    return 0;
}