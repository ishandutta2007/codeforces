#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
char s[200002];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%s", s);
        int i=0, c1=0, c2=0, d1=0, d2=0;
        while(s[i]!=0){
            if (s[i]=='(') c1++;
            else if (s[i]=='[') c2++;
            else if (c1 && s[i]==')'){
                c1--;
                d1++;
            }
            else if (c2 && s[i]==']'){
                c2--;
                d2++;
            }
            i++;
        }
        printf("%d\n", d1+d2);
    }
    return 0;
}