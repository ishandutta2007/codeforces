#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
     cin >> n;
     int nn = n;
     for(int i = 0; i<n; i++){
        if(i % 2 == 0){
            cout << i << " " << 2 << endl;
            nn--;
            if(nn == 0) return 0;
            cout << i << " "  << 0 << endl;
            nn--;
            if(nn == 0) return 0;
        }

        if(i % 2 == 1){
            cout << i << " " << 1 << endl;
            nn--;
            if(nn == 0) return 0;
        }
     }

}