#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, a;
    cin >> n >> m;

    int perm[n];
    int per[n];
    for(int i=0; i<n; i++){
        cin >> perm[i];
    }

    for(int i=0; i<n; i++){
        per[i]=perm[i];
    }

    int sorty[m][3];
    for(int i=0; i<m; i++){
        cin >> sorty[i][0] >> sorty[i][1] >> sorty[i][2];
    }

    for(int i=0; i<m; i++){

        a=0;

        for(int j=sorty[i][0]-1; j<sorty[i][1]; j++){
            if(perm[j]>perm[sorty[i][2]-1]) a++;
        }

        if(a==sorty[i][1]-sorty[i][2]) cout << "Yes" << endl;
        else cout << "No" << endl;

    }


}