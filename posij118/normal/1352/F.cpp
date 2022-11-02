#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n0, n1, n2;
        cin >> n0 >> n1 >> n2;

        if(n1 == 0){
            if(n0){
                for(int i = 0; i<n0 + 1; i++){
                    cout << '0';
                }
                cout << endl;
            }

            else{
                for(int i = 0; i<n2 + 1; i++){
                    cout << '1';
                }
                cout << endl;
            }
        }

        else if(n1 % 2){
            for(int i = 0; i<n0 + 1; i++){
                    cout << '0';
            }
            //cout << endl;

            for(int i = 0; i<n1 - 1; i++){
                char c = '1' - (i % 2);
                cout << c;
            }
            //cout << endl;

            for(int i = 0; i<n2 + 1; i++){
                    cout << '1';
            }
            cout << endl;
        }

        else{
             for(int i = 0; i<n0 + 1; i++){
                    cout << '0';
            }
            //cout << endl;

            for(int i = 0; i<n1 - 2; i++){
                    char c = '1' - (i % 2);
                    cout << c;
            }
            //cout << endl;

            for(int i = 0; i<n2 + 1; i++){
                    cout << '1';
            }
            //cout << endl;

            cout << '0' << endl;
        }
    }

}