#include <bits/stdc++.h>

using namespace std;

int gcd(int x, int y){
    if(x < y) swap(x, y);
    if(x%y == 0) return y;
    return gcd(x%y, y);
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        string s1, s2;
        cin >> s1 >> s2;
        int n = s1.size(), m = s2.size();
        int g = gcd(n, m);

        bool flag = true;
        for(int i=0;i<g;i++){
            if(s1[i] != s2[i]) flag = false;
        }
        for(int i=0;i<n;i++){
            if(s1[i] != s1[i%g]) flag = false;
        }
        for(int i=0;i<m;i++){
            if(s2[i] != s2[i%g]) flag = false;
        }
        if(!flag){
            printf("-1\n");
            continue;
        }

        for(int i=0;i<n*m/g/g;i++){
            for(int j=0;j<g;j++){
                printf("%c", s1[j]);
            }
        }
        printf("\n");
    }
}