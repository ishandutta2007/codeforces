#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    int k,sk,ind;
    k = 0;
    ind = 0;
    int tek;
    for(int j = 0;j<n;j++){
        cin >> sk;
        tek = sk/m;
        if(sk%m!=0){
            tek++;
        }
        if(tek >= k){
            k = tek;
            ind = j;
        }
    }
    cout << ind+1;
    return 0;
}