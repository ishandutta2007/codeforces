    //#pragma comment (linker, "/STACK:200000000")
    #include <cstdio>
    #include <iostream>
    #include <algorithm>
    #include <cstring>
    #include <string>
    #include <vector>
    #include <set>
    #include <map>
    #define pb push_back
    const double eps = 1e-9;
    const int inf = 2000000000;
    using namespace std;
    int x,y,a;

    int h(int y)
    {
            if (y<a) return a/2;
        if ((y/a)%2==0) return a;
        return a/2;
    }

    int main() {
       //freopen("input.txt","r",stdin);
       //freopen("output.txt","w",stdout);
       cin>>a>>x>>y;
       a*=2;x*=2;y*=2;
       if (y%a==0 || y==0 || x>=h(y) || x<=-h(y)) {puts("-1");return 0;}
       if (y<a) {cout << "1"; return 0;}
       if ((y/a)%2==0)
       {
               if (x==0) {cout<<"-1";return 0;}
               int g = y/a - 1;
               int res = 1;
               res+=(g/2)*2 + g - (g/2);
               if (x < 0) cout << res+1; else cout << res+2;
       } else
       {
               int g = (y/a) - 1;
               int res = 1;
               res+=(g/2)*2 + g - g/2;
               cout << res+1;
       }
       return 0;
    }