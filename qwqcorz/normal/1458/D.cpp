#include<bits/stdc++.h>
#define rep for(int i=1,s=n;i<=n;i++)
using namespace std;int T,n,e[1000005][2];char a[1000005];int main(){cin>>T;while (T--){cin>>a+1,n=strlen(a+1);rep if(a[i]=='1')e[s++][1]++;else e[s--][0]++;rep if(e[s][0]&&e[s-1][1])e[s--][0]--,cout<<0;else if(e[s][1])e[s++][1]--,cout<<1;else e[s--][0]--,cout<<0;puts("");}exit(0);}