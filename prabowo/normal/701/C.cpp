#include <bits/stdc++.h>
using namespace std;

int n;
char s[100005];

int poke[255];

int main () {
    scanf ("%d", &n);
    gets(s); gets(s);
    
    int mini = n;
    int maks = 0;
    int cnt = 0;
    int l = 0;
    
    for (int i=0; i<n; i++) {
        if (poke[s[i]]++ == 0) cnt++;
        
        while (poke[s[l]] > 1) poke[s[l++]]--;
        
        if (cnt > maks) {
            maks = cnt;
            mini = i - l + 1;
        } else if (cnt == maks) {            
            mini = min(mini, i - l + 1);
        }
    }
    
    printf ("%d\n", mini);
    
    
    return 0;
}