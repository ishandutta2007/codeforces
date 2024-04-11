#include <bits/stdc++.h>
using namespace std;

int main(){
    string s[20];
    int a=0;

    int primes[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    int squares[4] = {4, 9, 49, 25};
    for(int i=0; i<4; i++){
        cout << primes[i] << endl;
        fflush(stdout);
        cin >> s[i];
        if(s[i]=="yes") a++;
    }
    if (a>=2) cout << "composite";
    else if (s[0] == "yes" || s[1] == "yes" || s[2] == "yes" || s[3] == "yes"){
        for(int i=4; i<15; i++){
            cout << primes[i] << endl;
            fflush(stdout);
            cin >> s[i];
            if(s[i]== "yes"){
                cout << "composite";
                break;
            }

            if(i==14){
                    for(int j=0; j<4; j++){
                        cout << squares[j] << endl;
                        fflush(stdout);
                        cin >> s[15+j];
                        if(s[15+j]=="yes"){
                            cout << "composite";
                            break;
                        }

                        if(j==3) cout << "prime";
                    }

            }
        }
    }

    else cout << "prime";
}