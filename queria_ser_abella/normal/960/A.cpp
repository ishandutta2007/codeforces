#include <bits/stdc++.h>
using namespace std;
#define sq(x) ((x)*(x))
#define double long double
#define eps 1e-3
char ch[100100];

main(){
    scanf(" %s",ch);
    int n = strlen(ch);
    int ok = 1;
    int a=0, b=0,c=0;
    for(int i=0;i<n;i++){
        if(ch[i] < 'a' || ch[i] > 'c') ok = 0;
        if(i && ch[i] < ch[i-1]) ok = 0;
        if(i && ch[i] == 'c' && ch[i-1] == 'a') ok = 0;
        if(ch[i] == 'a')a++;
        if(ch[i] == 'b')b++;
        if(ch[i] == 'c')c++;
    }
    if(ch[0] != 'a') ok = 0;
    if(ch[n-1] == 'a') ok = 0;
    if(a != c && b != c) ok = 0;
    if(ok)printf("YES");
    else printf("NO");
}