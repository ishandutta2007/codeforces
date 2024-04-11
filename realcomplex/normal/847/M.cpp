#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int temp[n];
    for(int j = 0;j<n;j++){
        cin >> temp[j];
    }
    int k = temp[1]-temp[0];
    for(int j = 2;j<n;j++){
        if(temp[j]-temp[j-1]!=k){
            cout << temp[n-1];
            exit(0);
        }
    }
    cout << temp[n-1]+k;
    return 0;
}