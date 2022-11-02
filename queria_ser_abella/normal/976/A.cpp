#include <bits/stdc++.h>
#define maxn 300300
using namespace std;
#define pb push_back
#define pii pair<ll,ll>
#define pip pair<ll,pii>
#define debug 
#define ll long long
#define move ouehfri
#define left cjsbsoiyafg

char str[100100];

main(){
    int n;
    scanf("%d",&n);
    scanf(" %s",str);
    if(n == 1 && str[0] == '0'){
        printf("0\n");
        return 0;
    }
    int a = 0;
    for(int i=0;i<n;i++)
        if(str[i] == '0') a++;
    printf("1");
    for(int i=0;i<a;i++)
        printf("0");
    printf("\n");
}