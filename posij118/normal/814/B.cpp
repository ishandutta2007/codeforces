#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> x;
    vector<int> xx;

    int a[n];
    int b[n];

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    for(int i=0; i<n; i++){
        cin >> b[i];
    }


    int cisla[n+1];

    for(int i=0; i<n+1; i++){
        cisla[i]=0;
    }

    for(int i=0; i<n; i++){
        if(a[i]==b[i]) cisla[a[i]]=1;
    }

     for(int i=0; i<n; i++){
        if(a[i]!=b[i]) x.push_back(i);
    }

    for(int i=1; i<n+1; i++){
        if(cisla[i]==0) xx.push_back(i);
    }

    if(x.size()==1){
        b[x[0]]=xx[0];
        for(int i=0; i<n; i++){
            cout << b[i] << " ";
        }
    }

    if(x.size()==2){
        if( (a[x[0]] == xx[0] || b[x[0]] == xx[0]) && (a[x[1]] == xx[1] || b[x[1]] == xx[1])){

                b[x[0]]=xx[0];
                b[x[1]]=xx[1];

                for(int i=0; i<n; i++){
                    cout << b[i] << " ";
                }


           }

        else {
             b[x[0]]=xx[1];
                b[x[1]]=xx[0];

                for(int i=0; i<n; i++){
                    cout << b[i] << " ";
                }
        }
    }
}