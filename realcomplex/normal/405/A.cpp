#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main()
{
    int n;
    cin >> n;
    int sk[n];
    for(int i = 0;i<n;i++){
        cin >> sk[i];
    }
    sort(sk,sk + n);
    for(int i = 0;i<n;i++){
        cout << sk[i] << " ";
    }
    return 0;
}