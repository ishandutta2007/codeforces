#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define fi first
#define se second

int main(){

    int n,m;
    cin >> n >> m;
    char s;
    for(int i = 0;i<n;i++){
        for(int x = 0;x<m;x++){
            cin >> s;
            if(s == '.'){
                if(i%2 == 0){
                    if(x%2 == 0){
                        cout << "B";
                    }
                    else{
                        cout << "W";
                    }
                }
                else{
                    if(x%2 == 0){
                        cout << "W";
                    }
                    else{
                        cout << "B";
                    }
                }
            }
            else{
                cout << "-";
            }
        
        }
        cout << "\n";
    }
    return 0;
}