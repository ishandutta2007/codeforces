#include <bits/stdc++.h>

using namespace std;
int n;
int t[200001];
int e[200001];
int h[200001];
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    int k=1;
    while (t[k]!=0){
        e[k]=INT_MAX;
        k++;
    }
    for (int i=k+1; i<=n; i++) {
        e[i]=e[i-1]+1;
        if (t[i]==0) {
            e[i]=0;
        }
    }
    int p=n;
    while (t[p]!=0){
        h[p]=INT_MAX;
        p--;
    }
    for (int i=p-1; i>=1; i--) {
        h[i]=h[i+1]+1;
        if (t[i]==0) {
            h[i]=0;
        }
    }
    for (int i=1; i<=n; i++) {
        cout << min (e[i], h[i]) << " ";
    }
    return 0;
}