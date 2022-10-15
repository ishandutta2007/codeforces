#include <bits/stdc++.h>
 
#define ll long long
#define pb(x) push_back(x)
 
using namespace std;
 
typedef pair<int,int> ii;
 
const int NMAX = 1e5+5;
 
set<long double> s;
 
int main()
{
    int N,i,j;
 
    cin>>N;
    for(i = 1 ; i <= N ; ++i)
    {
        int k,b;
        cin>>k>>b;
        if(k != 0)
            s.insert((long double)-b/k);
    }
    cout<<s.size();
}