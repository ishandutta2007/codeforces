#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    int gi[n];
    for(int i = 0;i<n;i++){
        cin >> gi[i];
    }
    int m;
    cin >> m;
    int bo[m];
    for(int i = 0;i<m;i++){
        cin >> bo[i];
    }
    sort(gi,gi+n);
    sort(bo,bo+m);
    int pa = 0;
    for(int i = 0;i<m;i++){
        for(int x = 0;x<n;x++){
            if(abs(bo[i]-gi[x]) <= 1){
                gi[x] = 1e9;
                pa++;
                break;
            }
        }
    }
    cout << pa;
    return 0;

}