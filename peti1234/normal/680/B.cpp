#include <bits/stdc++.h>

using namespace std;
int t[101];
int main()
{
    int n, lakhely;
    cin >> n >> lakhely;
    for (int i=1; i<n+1; i++){
        cin >> t[i];
    }
    int osszeg=0;
    for (int i=0; i<n; i++){
         if (i==0 && t[lakhely]==1){
            osszeg++;
            continue;
         }
         if (lakhely-i>0 && lakhely+i<n+1 && t[lakhely+i]+t[lakhely-i]==2) osszeg+=2;
         if (lakhely-i<=0 && lakhely+i<n+1 && t[lakhely+i]==1) osszeg+=1;
         if (lakhely-i>0 && lakhely+i>=n+1 && t[lakhely-i]==1) osszeg+=1;
    }
    cout << osszeg << endl;
    return 0;
}