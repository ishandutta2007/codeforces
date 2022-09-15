#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int mex(vector<ll>v){
    sort(v.begin(),v.end());
   int last=-1;
   for (auto i:v){
       if (i>last+1) return last+1;
       last=i;
   }
   return last+1;
}
int g[101];
// Complete the winner function below.

int main()
{
    int x,y,z;cin>>x>>y>>z;
    if (x==y && z==0) cout<<0;
    else if (x-y-z>0) cout<<"+";
    else if (y-x-z>0) cout<<"-";
    else cout<<"?";
    return 0;
}
//1-0
//3-1
//5-2
//7 3
//9 4