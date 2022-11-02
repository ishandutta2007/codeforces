#include <bits/stdc++.h>
using namespace std;

int cislo(char c){
    if(c=='A') return 0;
    else if(c=='B') return 1;
    else if(c=='C') return 2;
    else if(c=='D') return 3;
    else if(c=='E') return 4;
    else if(c=='F') return 5;
    else if(c=='G') return 6;
    else if(c=='H') return 7;
    else if(c=='I') return 8;
    else if(c=='J') return 9;
    else if(c=='K') return 10;
    else if(c=='L') return 11;
    else if(c=='M') return 12;
    else if(c=='N') return 13;
    else if(c=='O') return 14;
    else if(c=='P') return 15;
    else if(c=='Q') return 16;
    else if(c=='R') return 17;
    else if(c=='S') return 18;
    else if(c=='T') return 19;
    else if(c=='U') return 20;
    else if(c=='V') return 21;
    else if(c=='W') return 22;
    else if(c=='X') return 23;
    else if(c=='Y') return 24;
    else if(c=='Z') return 25;
}


int main(){
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int last[26];
    int first[26];
    fill(last, last + 26, -1);
    fill(first, first + 26, n);

    for(int i=0; i<26; i++){
        for(int j=0; j<n; j++){
            if(cislo(s[j])==i){
                first[i]=j;
                break;
            }
        }

        for(int j=n-1; j>-1; j--){
            if(cislo(s[j])==i){
                last[i]=j;
                break;
            }
        }
    }

    int cnt[n];
    fill(cnt, cnt + n, 0);
    for(int i=0; i<26; i++){
        for(int j=first[i]; j<=last[i]; j++){
            cnt[j]++;
        }
    }

    for(int i=0; i<n; i++){
        if(cnt[i]>k){
            cout << "YES";
            break;
        }

        if(i==n-1) cout << "NO";
    }



}