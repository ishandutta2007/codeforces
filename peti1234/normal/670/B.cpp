#include <bits/stdc++.h>

using namespace std;
int t[100001];
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i=1; i<n+1; i++){
        cin >> t[i];
    }
    int novekvo=1;
    while (k-novekvo>0) {
        k-=novekvo;
        novekvo++;
    }
    cout << t[k];
    return 0;
}