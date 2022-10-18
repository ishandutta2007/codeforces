    #include <cstdio>
    #include <iostream>
    #include <algorithm>
    #include <cstring>
    #include <string>
    #include <vector>
    #include <set>
    #include <map>
    #define pb push_back
    #define i64 long long
    const double eps = 1e-9;
    const i64 inf = 1ll<<61;
    using namespace std;
    i64 resmin = inf;
    i64 resmax = -inf;
    int n;

    void go(int d)
    {
            int A = d+1;
            int g = n / d;
            for (int i=1; i*i<=g; i++)
                    if (g % i==0) 
                    { 
                     resmin = min(resmin,(i64)A*(i+2ll)*((g/i)+2ll)); 
                     resmax = max(resmax,(i64)A*(i+2ll)*((g/i)+2ll)); 
                    }
            resmin = min(resmin,(i64)A*(g+2ll)*3ll);
            resmax = max(resmax,(i64)A*(g+2ll)*3ll);            
    }

    int main() {
       cin >> n;
       for (int i=1;i*i<=n;i++)
               if (n % i == 0) go(i);
               
       go(n);
       cout << resmin - n << " " << resmax - n << endl;
       return 0;
    }