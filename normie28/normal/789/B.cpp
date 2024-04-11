#include <bits/stdc++.h>
using namespace std;
vector<long long int> v;
long long int ab(long long int x)
{
    return (x>0)?x:-1*x;
}
bool keres(int x,int kez,int veg)
{
    if (kez>veg) return false;
    int koz=(kez+veg)/2;
    if (v[koz]==x) return true;
    else if (v[koz]<x) return keres(x,koz+1,veg);
    else return keres(x,kez,koz-1);
}
int main()
{
 long long   int a,b,l,m,ki=0,z=0;
    cin>>a>>b>>l>>m;
 
    for (int i=0;i<m;i++)
    {
        v.push_back(0);
        cin>>v[i];
    }
    sort(v.begin(),v.end());
 
 
    for (;ab(a)<=l;a*=b)
    {
        if (!keres(a,0,m-1)) ki++;
        if (ab(a)==ab(z)) {
 
          cout<<((ki==0)?"0":"inf")<<endl;
          return 0;
        }
        if (a==0 && !keres(0,0,m-1))
        {
            cout<<"inf"<<endl;
            return 0;
        }
        else if (a==0)
        {
            cout<<ki<<endl;
            return 0;
        }
        z=a;
    }
cout<<ki<<endl;
}