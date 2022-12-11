#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define f first
#define s second

int main(){

    int n;
    cin >> n;
    cout << ((n*n)/2) + ((n*n)%2) << "\n";
    for(int i = 0;i<n;i++){
        for(int x = 0;x<n;x++){
            if((i%2 == 0 && x%2 == 0) || (i%2 == 1 && x%2 == 1)){
                cout << "C";
            }
            else{
                cout << ".";
            }
        }
        cout << "\n";
    }
    return 0;
}