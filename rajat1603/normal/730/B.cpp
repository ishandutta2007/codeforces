#include "bits/stdc++.h"
using namespace std;
const int N = 55;
int t;
int n;
int mini[N];
int maxi[N];
int main(){
    scanf("%d" , &t);
    while(t--){
        scanf("%d" , &n);
        for(int i = 1 ; i <= n ; i += 2){
            if(i == n){
                mini[i] = i;
                maxi[i] = i;
            }
            else{
                cout << "? " << i << " " << i + 1 << endl;
                fflush(stdout);
                char c;
                cin >> c;
                if(c == '<' || c == '='){
                    mini[i] = i;
                    maxi[i] = i + 1;
                }
                else{
                    maxi[i] = i;
                    mini[i] = i + 1;
                }
            }
        }
        int mn = mini[1];
        int mx = maxi[1];
        for(int i = 3 ; i <= n ; i += 2){
            cout << "? " << mn << " " << mini[i] << endl;
            fflush(stdout);
            char c;
            cin >> c;
            if(c == '>'){
                mn = mini[i];
            }
            cout << "? " << mx << " " << maxi[i] << endl;
            fflush(stdout);
            cin >> c;
            if(c == '<'){
                mx = maxi[i];
            }
        }
        cout << "! " << mn << " " << mx << endl;
        fflush(stdout);
    }
}