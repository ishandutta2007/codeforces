#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int l[5];
    for(int i=0; i<4; i++){
        cin >> s;
        l[i] = s.length()-2;
    }

    int i,n = 0;
    char c;
    for(i=0; i<4; i++){
        bool ans = false;
        int cnt = 0;
        for(int j=0; j<4; j++){
            if (i != j && 2*l[i]<=l[j]) cnt++;
            if (cnt == 3) ans = true;
        }
        cnt = 0;
        for (int j=0; j<4; j++){
            if (i != j && l[i] >= 2*l[j]) cnt++;
            if (cnt == 3) ans = true;
        }
        if (ans){
            n++;
            if (i == 0) c = 'A';
            if (i == 1) c = 'B';
            if (i == 2) c = 'C';
            if (i == 3) c = 'D';
        }
    }
    if (n == 1) cout << c; else cout << "C";
    cout << endl;
    return 0;
}