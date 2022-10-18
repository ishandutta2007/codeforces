    //#pragma comment (linker, "/STACK:200000000")
    #include <cstdio>
    #include <iostream>
    #include <algorithm>
    #include <cstring>
    #include <string>
    #include <vector>
    #include <bitset>
    #include <set>
    #include <map>
    #define pb push_back
    #define eps 1e-9
    const int inf=2000000000;

    using namespace std;
    int n; int m;

    struct room
    {
            int a,b,h;
    };
    struct rulon
    {
            int l,d,c;
    };

    room k[511];
    rulon r[511];

    int c(room kom,rulon rul)
    {
            int q=(2*kom.a+2*kom.b)/rul.d;
            if ((2*kom.a+2*kom.b)%rul.d!=0) q++;
           
            if (kom.h>rul.l) return inf;
            int e=rul.l/kom.h;
            int need=q/e;
            if (q%e!=0) need++;
            return need*rul.c;
    }

    int main() {
      // freopen("input.txt","r",stdin);
       //freopen("output.txt","w",stdout);
       scanf("%d",&n);
       for (int i=1;i<=n;i++)
               scanf("%d%d%d",&k[i].a,&k[i].b,&k[i].h);
       scanf("%d",&m);
       for (int i=1;i<=m;i++)
               scanf("%d%d%d",&r[i].l,&r[i].d,&r[i].c);
       
       long long res=0;
       for (int i=1;i<=n;i++)
       {
               int ans=inf;
               for (int j=1;j<=m;j++)
                       ans=min(ans,c(k[i],r[j]));
               res+=ans;
       }
       cout<<res;
       return 0;
    }