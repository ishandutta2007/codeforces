#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

main(){
    int n;
    scanf("%d",&n);
    set<pii> intro, extro;
    for(int i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        intro.insert(pii(a,i+1));
    }
    for(int i=0;i<2*n;i++){
        char ch;
        scanf(" %c",&ch);
        if(ch == '0'){
            pii u = *(intro.begin());
            intro.erase(u);
            printf("%d ",u.second);
            extro.insert(u);
        }
        else {
            pii u = *(--extro.end());
            extro.erase(u);
            printf("%d ",u.second);
        }
    }
}