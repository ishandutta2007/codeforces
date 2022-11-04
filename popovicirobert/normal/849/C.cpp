#include <bits/stdc++.h>
#define ll long long


using namespace std;

const int MAXN = (int) 1e5;

int fr[26];

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int k;
    ios::sync_with_stdio(false);
    cin >> k;
    if(k == 0) {
        cout << 'a';
        return 0;
    }
    char ch = 0;
    int i = (int) 44000;
    while(k > 0) {
        while(k >= i * (i - 1) / 2) {
            k -= i * (i - 1) / 2;
            fr[ch] = i;
            ch++;
        }
        i--;
    }
    for(i = 0; i < ch; i++) {
        while(fr[i] > 0) {
            cout << (char) (i + 'a');
            fr[i]--;
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}