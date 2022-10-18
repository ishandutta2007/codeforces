#include <cstdio>
#include <iostream>
#include <vector>
#define forn(i,n) for (int (i)=0; (i)<(n); ++(i))
#define pb push_back
using namespace std;
vector <string> piz,tax,girl;
int mpiz = 0,mtax = 0,mgirl = 0;

int main()
{
    int n; cin >> n;
    forn(i,n)
    {
     string name; int s;
     cin >> s >> name;
     int tpiz = 0,ttax = 0,tgirl = 0;
     forn(j,s)
     {
      int t1,t2,t3;
      scanf("%d-%d-%d",&t1,&t2,&t3);
      if (t1/10 == t1%10 && t2/10 == t2%10 && t3/10 == t3%10 && t1 == t2 && t2 == t3) ttax++;
       else
      if (t1/10 > t1%10 && t1%10 > t2/10 && t2/10 > t2%10
      && t2%10 > t3/10 && t3/10 > t3%10) tpiz++; else tgirl++;
     }
     if (ttax == mtax) tax.pb(name);
     if (ttax > mtax) { tax.clear(); mtax = ttax; tax.pb(name); }
     if (tpiz == mpiz) piz.pb(name);
     if (tpiz > mpiz) { piz.clear(); mpiz = tpiz; piz.pb(name); }
     if (tgirl == mgirl) girl.pb(name);
     if (tgirl > mgirl) { girl.clear(); mgirl = tgirl; girl.pb(name); }
    }
    
    cout << "If you want to call a taxi, you should call: ";
    forn(i,(int)tax.size()) 
    { cout << tax[i]; if (i<(int)tax.size()-1) cout << ", "; else cout << "."; }
    cout << endl; 
    
    cout << "If you want to order a pizza, you should call: ";
    forn(i,(int)piz.size()) 
    { cout << piz[i]; if (i<(int)piz.size()-1) cout << ", "; else cout << "."; }
    cout << endl; 
    
    cout << "If you want to go to a cafe with a wonderful girl, you should call: ";
    forn(i,(int)girl.size()) 
    { cout << girl[i]; if (i<(int)girl.size()-1) cout << ", "; else cout << "."; }
    cout << endl; 
    return 0;
}