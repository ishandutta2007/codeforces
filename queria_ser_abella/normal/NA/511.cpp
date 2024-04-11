#include <bits/stdc++.h>
#define maxn 1001000
using namespace std;
#define pb push_back
#define pii pair<int,int>
#define pip pair<ll,pii>
#define debug 
#define ll long long

char str[110];

main(){
    scanf(" %s",str);
    int n = strlen(str);
    int a = 0, b = 0;
    for(int i=0;i<n;i++){
        if(str[i] == 'o') a++;
        else b++;
    }
    if(a == 0)
        printf("YES\n");
    else if(b%a != 0)
        printf("NO\n");
    else
        printf("YES\n");
}