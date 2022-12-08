#include <iostream> 
#include <set> 
#include <algorithm> 
using namespace std; 
multiset <long long> a; 
long long k; 
int main() 
{ 
ios_base::sync_with_stdio(0);
cin.tie(0); 
long long n; 
cin >>n >>k; 
long long x,y; 
for (int i=0; i<k; i++) 
{ 
cin >>x >>y; 
a.insert(x+y); 
cout <<x+y <<"\n"; 
} 
for (int i=k; i<n; i++) 
{ 
cin >>x >>y; 
cout <<max(x,*a.begin())+y <<"\n"; a.insert(max(x,*a.begin())+y); 
a.erase(a.begin()); 
} 
return 0; 
}