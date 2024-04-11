#include<bits/stdc++.h>

using namespace std;

long long int a[10001];

int main()
{
    long long int n,m,s,rez;
    cin>>n>>m;
    rez=0;
    if (m==1) cout<<n*n;
    else{
        for (long long int i=1;i<=m;i++){
            a[(i*i)%m]++;
        }
        s=n/m;
        for (long long int i=0;i<m;i++){
            a[i]=a[i]*s;
        }
        for (long long int i=s*m+1;i<=n;i++){
            a[(i*i)%m]++;
        }
       /* for (long long int i=0;i<m;i++) {
                cout<<i<<" "<<a[i]<<endl;
        }*/
        for (long long int i=1;i<m;i++){
            rez+=a[i]*a[m-i];
        }
        rez+=a[0]*a[0];
        /*string z="";
        while (rez){
            z+=char((rez%10)+'0');
        }*/
        cout<<rez;
    }
    return 0;
    //7889988990 789
}