#include <bits/stdc++.h>
using namespace std;
 
int main(void) {
    int a;
    scanf("%d",&a);
    for(int i=2;i<a;i++) {
        if (a%i==0) {
            printf("%d%d",i,a/i);
            return 0;
        }
    }
}