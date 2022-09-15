#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[300001];
int b[300001];
int n;
bool ok(int pos){
    if (pos==0) return 0;
     for (int i=pos+1;i<=n;i++){
        if (b[i]!=i-pos+1) return 0;
     }
     return true;
}
int p[300001];
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    for (int i=1;i<=n;i++) p[b[i]]=i;
    int pos=0;
    for (int i=1;i<=n;i++){
        if (b[i]==1) pos=i;
    }
    if (ok(pos)){
        int last=b[n];
        bool okk=true;
        for (int i=last+1;i<=n;i++){
            if (p[i]>i-last-1) okk=false;
        }
        if (okk){
           cout<<n-last;
           return 0;
        }
    }
    int maxx=0;
    for (int i=1;i<=n;i++){
       // cout<<i<<" "<<n-i+1+p[i]<<endl;
        maxx=max(n-i+1+p[i],maxx);
    }
    cout<<maxx;
    return 0;
}
//1-0
//3-1
//5-2
//7 3
//9 4