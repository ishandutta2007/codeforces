#include <bits/stdc++.h>
using namespace std;

int main(){
    int q, num;
    cin >> q;

    for(int i=0; i<q; i++){
        cin >> num;
        if(num%4==0){
            cout << num/4 << endl;
        }

        else if(num%4==1){
            if(num>=9) cout << num/4-1 << endl;
            else cout << "-1" << endl;
        }

        else if(num%4==2){
            if(num>=6) cout << num/4 << endl;
            else cout << "-1" << endl;
        }

        else{
            if(num>=15) cout << num/4-1 << endl;
            else cout << "-1" << endl;
        }
    }

}