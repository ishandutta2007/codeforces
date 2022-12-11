#include <bits/stdc++.h>

using namespace std;

int cnt[10];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    for(int j = 0;j<6;j++){
        cin >> n;
        cnt[n]++;
    }
    bool is = false;
    for(int x = 0;x<10;x++){
        if(cnt[x] >= 4){
            cnt[x] -= 4;
            is = true;
        }
    }
    if(is == false){
        cout << "Alien";
    }
    else{
        int f,s;
        f = -1;
        s = -1;
        for(int j = 0;j<10;j++){
            if(cnt[j] == 2){
                cout << "Elephant";
                exit(0);
            }
        }
        if(f == s){
            cout << "Bear";
        }
    }
    return 0;
}