#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    int pebelT[n];
    for(int x = 0;x<n;x++){
        cin >> pebelT[x];
    }
    sort(pebelT,pebelT + n);
    int skait = 0;
    for(int i = 0;i<n;i++){
        if(pebelT[i] % k == 0){
            skait += (pebelT[i] / k);
        }
        else{
            skait += (pebelT[i] / k) + 1;
        }
    }
    if(skait % 2 != 0){
        cout << (skait / 2) + 1;
    }
    else{
        cout << skait / 2;
    }
    return 0;
}