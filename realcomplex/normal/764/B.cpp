#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second


int main()
{
    int n;
    cin >> n;
    int c[n];
    for(int i = 0;i<n;i++){
        cin >> c[i];
    }
    int s = n-1;
    for(int x = 0;x<n/2;x++){
        if(x%2==0){
            swap(c[x],c[s]);
        }
        s--;
    }
    for(int i = 0;i<n;i++){
        cout << c[i] << " ";
    }
    return 0;
}