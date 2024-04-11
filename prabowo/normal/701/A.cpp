#include <bits/stdc++.h>
using namespace std;

const int N = 100;

int n;
int a[N];
bool vis[N];

int main () {
    scanf ("%d", &n);
    
    int sum = 0;
    for (int i=0; i<n; i++) {
        scanf ("%d", a + i);
        sum += a[i];
    }
    
    sum /= n >> 1;
    
    for (int i=0; i<n; i++) {
        if (vis[i]) continue;
        
        int j = i + 1;
        while (vis[j] || a[i] + a[j] != sum) j++;
        
        vis[i] = vis[j] = 1;
        printf ("%d %d\n", i+1, j+1);
    }
    
    return 0;
}