#include <bits/stdc++.h>
#define sq(x) ((x)*(x))
#define pb push_back
#define debug 
typedef long long ll;
using namespace std;

char str[222];

int main(){
    int n;
    scanf("%d",&n);
    scanf(" %s",str);
    int q8 = 0;
    for(int i=0;i<n;i++)
        q8 += (str[i] == '8');
    int ans = 0;
    for(int i=1;i<100;i++)
        if(q8 >= i && n >= 11*i) ans = i;
    printf("%d\n",ans);
    
}