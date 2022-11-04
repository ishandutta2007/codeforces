#include <bits/stdc++.h>


using namespace std;


string str;

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
   // int ;
    ios::sync_with_stdio(false);
    cin >> str;
    int i, j;
    if(str.size() % 2 == 1) {
        i = ((int)str.size() - 3) / 2;
        j = i + 2;
        char ch = str[j - 1];
        if(ch != 'A' && ch != 'H' && ch != 'I' && ch != 'M' && ch != 'O' && ch != 'T' && ch != 'U' && ch != 'V' && ch != 'W' && ch != 'X' && ch != 'Y' && ch != 'o' && ch != 'v' && ch != 'w' && ch != 'x') {
            cout << "NIE";
            return 0;
        }
    }
    else {
        i = ((int)str.size() - 1) / 2;
        j = i + 1;
    }
    while(i >= 0) {
        char a = str[i];
        char b = str[j];
        if(a == 'A' || a == 'H' || a == 'I' || a == 'M' || a == 'O' || a == 'T' || a == 'U' || a == 'V' || a == 'W' || a == 'X' || a == 'Y') {
            if(a != b) {
                cout << " NIE";
                return 0;
            }
        }
        else if(a == 'o' || a == 'v' || a == 'w' || a == 'x') {
            if(a != b) {
                cout << "NIE";
                return 0;
            }
        }
        else if(a == 'b') {
            if(b != 'd') {
                cout << "NIE";
                return 0;
            }
        }
        else if(a == 'd') {
            if(b != 'b') {
                cout << "NIE";
                return 0;
            }
        }
        else if(a == 'p') {
            if(b != 'q') {
                cout << "NIE";
                return 0;
            }
        }
        else if(a == 'q') {
            if(b != 'p') {
                cout << "NIE";
                return 0;
            }
        }
        else {
            cout << "NIE";
            return 0;
        }
        i--;
        j++;
    }
    cout << "TAK";
    //cin.close();
    //cout.close();
    return 0;
}