#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
char a[N];
char b[N];
int n , m;
int main(){
    scanf("%s" , a);
    scanf("%s" , b);
    n = strlen(a);
    m = strlen(b);
    reverse(a , a + n);
    reverse(b , b + m);
    while(n < m){
        a[n++] = '0';
    }
    while(m < n){
        b[m++] = '0';
    }
    while(n--){
        if(a[n] > b[n]){
            printf(">");
            return 0;
        }
        else if(a[n] < b[n]){
            printf("<");
            return 0;
        }
    }
    printf("=");
}