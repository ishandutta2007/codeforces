#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    char a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    for(int i=1; i<n; i++){
        if(a[i]!='?'){
            if(a[i]==a[i-1]){
                cout << "No";
                return 0;
            }
        }
    }

    if(a[0]=='?' || a[n-1]=='?'){
        cout << "Yes";
        return 0;
    }

    for(int i=1; i<n; i++){
        if(a[i]=='?' && a[i-1]=='?'){
            cout << "Yes";
            return 0;
        }
    }

    for(int i=1; i<n-1; i++){
        if(a[i]=='?'){
            if(a[i-1]==a[i+1]){
                cout << "Yes";
                return 0;
            }
        }
    }

    cout << "No";

}