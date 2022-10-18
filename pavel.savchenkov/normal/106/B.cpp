#include <iostream>

using namespace std;

int main() {
    int n;
    cin>>n;
    int a[n],b[n],c[n],d[n];
    bool old[n];
    for (int i=1;i<=n;i++)
        old[i]=false;
    for (int i=1;i<=n;i++)
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
          if (a[i]<a[j]&b[i]<b[j]&c[i]<c[j]) old[i]=true; else 
              if (a[i]>a[j]&b[i]>b[j]&c[i]>c[j]) old[j]=true; 
    int min=1001,m;
    for (int i=1;i<=n;i++)
        if (!old[i]&d[i]<min) {min=d[i];m=i;}
    cout<<m;
    return 0;
}