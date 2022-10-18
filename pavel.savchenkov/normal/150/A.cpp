#include <cstdio>
#include <iostream>
#include <vector>
#define i64 long long
#define pb push_back
using namespace std;

i64 pow(i64 a,i64 n)
{
    if (n == 0) return 1;
    if (n == 1) return a;
    if (n&1) return a*pow(a,n/2)*pow(a,n/2); else return pow(a,n/2)*pow(a,n/2);
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    i64 q;
    cin >> q;
    i64 qq = q;
    vector <i64> p;
    vector <i64> a;
    
    for (i64 i=2; i*i<=qq; i++)
    {
     if (i > q) break;
     if (q%i != 0) continue;
     int np = 0;
     while (q%i == 0)
     {
           np++; q/=i;
     }
     a.pb(i);p.pb(np);
    }
    
    if (q != 1 || qq == 1) { a.pb(q); p.pb(1); }
    
   // for (int i=0;i<(int)p.size();i++)
    // cout << a[i] << " " << p[i] << endl;
    
    if ((int)a.size() == 1)
    {
     if (p[0] == 1) { cout << "1" << endl << "0"; return 0; }
     if (p[0] == 2) { cout << "2" << endl; return 0; }
     cout << "1" << endl << qq/pow(a[0],p[0]-2);
     return 0;
    }
    
    if ((int)a.size() == 2)
    {
     if (p[0] == 1 && p[1] == 1) { cout << "2"; return 0; }
     i64 res = 1;
     if (p[0] != 1) res *= pow(a[0],p[0]-1);
     if (p[1] != 1) res *= pow(a[1],p[1]-1);
     cout << "1" << endl << qq/res << endl;
     return 0;
    }
    
    int sz = 0;
    i64 res = 1;
    
    for (int i=0; i<(int)a.size(); i++)
     if (sz == 2) res *= pow(a[i],p[i]);
      else { res *= pow(a[i],p[i]-1); sz++; }
      
    cout << "1" << endl << qq/res << endl;
    return 0;
}