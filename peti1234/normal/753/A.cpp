#include <bits/stdc++.h>

using namespace std;
int n;
int k;
int main()
{
    cin >> n;
    int j=1;
    while (n>=k) {
        k=(j*(j+1))/2;
        j++;
    }
    j-=2;
    cout << j << endl;
    for (int i=1; i<j; i++) {
        cout << i <<  " ";
        n-=i;
    }
    cout << n;
    return 0;
}