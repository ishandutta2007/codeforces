#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    //freopen("sq.txt","w",stdout);
    int n;
    cin >> n;
    for(int i = 0;i<=n;i++){
        for(int x = 0;x<n - i;x++){
            cout << "  ";
        }
        for(int x = 0;x<=i;x++){
            cout << x;
            if(x != i){
                cout << " ";
            }
        }
        for(int x = i - 1;x>=0;x--){
            cout << " " << x;
        }
        cout << "\n";
    }
    for(int i = n - 1;i>=0;i--){
        for(int x = 0;x<n - i;x++){
            cout << "  ";
        }
        for(int x = 0;x<=i;x++){
            cout << x;
            if(x != i){
                cout << " ";
            }
        }
        for(int x = i - 1;x>=0;x--){
            cout << " "<<x;
        }
        cout << "\n";
    }
	return 0;
}