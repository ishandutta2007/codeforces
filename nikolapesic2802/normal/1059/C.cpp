#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;
void resi(int n,int d)
{
    if(n==1){
        printf("%i\n",d);
        return;
    }
    if(n==2){
        printf("%i %i\n",d,2*d);
        return;
    }
    if(n==3){
        printf("%i %i %i\n",d,d,3*d);
        return;
    }
    int br=(n+1)/2;
    for(int i=0;i<br;i++){
        printf("%i ",d);
    }
    resi(n-br,2*d);
}
int main()
{
    int n;
    scanf("%i",&n);
    resi(n,1);
    return 0;
}