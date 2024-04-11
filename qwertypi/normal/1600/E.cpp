#include <bits/stdc++.h>
 
using namespace std;
 
int L = 1, R = 1;
int A[200001];
 
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    if(n == 1){
        cout << "Alice" << endl;
        return 0;
    }
    if(A[0] != A[n - 1]){
        for(int i = 0; i < n - 1; i++){
            if(A[i + 1] > A[i]) L++;
            else break;
        }
        for(int i = n - 2; i >= 0; i--){
            if(A[i] > A[i + 1]) R++;
            else break;
        }
        if(A[0] > A[n - 1]){
            if(L % 2 == 1){
                cout << "Alice" << endl;
            }else if(R % 2 == 1){
                cout << "Alice" << endl;
            }else{
                cout << "Bob" << endl;
            }
        }else{
            if(R % 2 == 1){
                cout << "Alice" << endl;
            }else if(L % 2 == 1){
                cout << "Alice" << endl;
            }else{
                cout << "Bob" << endl;
            }
        }
    }else{
        for(int i = 0; i < n - 1; i++){
            if(A[i + 1] > A[i]) L++;
            else break;
        }
        for(int i = n - 2; i >= 0; i--){
            if(A[i] > A[i + 1]) R++;
            else break;
        }
        if(L % 2 || R % 2){
            cout << "Alice" << endl;
        }else{
            cout << "Bob" << endl;
        }
    }
}