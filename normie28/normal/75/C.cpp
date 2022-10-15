#include <bits/stdc++.h>
#define pi 3.14159265359
using namespace std ;
int n , m , x , y  , counter , c , h;
vector <int> v ;
string s ;
 
int gcd(int a, int b) {
   if (b==0) return a;
   return gcd(b, a % b);
}
 
int main(){
    cin >> x >> y ;
    int cd = gcd(x,y);
    for(int i = 1 ; i <= sqrt(cd) ;i++)
    {
        if(!(cd%i))
        {
            if(i*i == cd )
                v.push_back(i);
            else
            {
                v.push_back(i);
                v.push_back(cd/i);
            }
        }
    }
    sort(v.begin(),v.end());
    /*for(int i = 0 ; i < v.size() ; i++ )
        cout << v[i] << " " ;
    cout << endl;*/
    cin >> n ;
    while(n--)
    {
        cin >> x >> y ;
        int i = lower_bound(v.begin(),v.end(),y) - v.begin();
        if(v[i] != y)
            i--;
        if(v[i]<x)
            cout << -1 << endl;
        else
            cout << v[i] << endl;
    }
 
}